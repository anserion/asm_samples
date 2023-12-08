BITS 32

%include "messages.inc"
%include "winstyles.inc"
%include "gl.inc"
%include "glu.inc"

global _main     ;точка входа в программу
global img1    ;указатель на картинку с изображением текстуры
global img1_dx ;ширина изображения для текстуры
global img1_dy ;высота изображения для текстуры

global texture1 ;указатель на текстуру в формате OpenGL
global t1_dx ;ширина текстуры
global t1_dy ;высота текстуры

extern DrawScene   ;Внешняя процедура рисования
extern LoadFromBMP ;процедура загрузки файла в формате BMP 24bpp
extern MakeTexture ;процедура преобразования картинки в формат текстуры OpenGL

extern _sprintf  
extern _memset
extern _malloc
extern _free
extern _printf

extern _MessageBoxA@16
extern _GetModuleHandleA@4
extern _CreateWindowExA@48
extern _LoadIconA@8
extern _LoadCursorA@8
extern _DefWindowProcA@16
extern _PostQuitMessage@4
extern _RegisterClassExA@4
extern _ShowWindow@8
extern _UpdateWindow@4
extern _GetMessageA@16
extern _TranslateMessage@4
extern _DispatchMessageA@4
extern _GetClientRect@8
extern _DrawTextA@20
extern _SendMessageA@16
extern _GetWindowTextA@12
extern _SetWindowTextA@8
extern _GetWindowTextLengthA@4
extern _SetScrollPos@16
extern _SetScrollRange@20

extern _GetDC@4             ;получить графический контекст устройства
extern _DeleteDC@4          ;освободить графический контекст устройства
extern _ChoosePixelFormat@8 ;определить глубину цвета
extern _SetPixelFormat@12   ;установить глубину цвета рисования
extern _wglCreateContext@4  ;создать графический контекст OpenGL
extern _wglDeleteContext@4  ;освободить графический контекст OpenGL
extern _wglMakeCurrent@8    ;сделать контекст OpenGL текущим
extern _glMatrixMode@4      ;выбор типа матрицы проецирования
extern _glLoadIdentity@0    ;загрузка тождественной матрицы проецирования
extern _gluOrtho2D@32       ;выбрать тип ортогонального проецирования
extern _glClearColor@16     ;установить цвет очистки

segment .stack use 32
stack times 1000 db 0

segment .data use 32
wc times 12 dd 0  ;класс главного окна
msg times 6 dd 0  ;сообщения, передаваемые программе от Windows
pfd times 40 db 0 ;описатель формата графики (PixelFormatDescriptor)
nPixelFormat dd 0 ;уточнение формата графики

winclass db "CLASS32",0
winhwnd dd 0
progtitle db "Win_gl",0
fmt_dec db "%d",13,10,0

f_zero 	dd 0.0 ;т.к. функции OpenGL работают с вещественными
f_one 	dd 1.0 ;переменными, то чтобы не использовать сопроцессор
q_zero 	dq 0.0 ;опишем наиболее часто встречающиеся константы
q_one 	dq 1.0 ;непосредственно в сегменте данных
;-------------------------------------------------------
img1 dd 0     ;указатель на содержимое графического файла BMP 24bpp
img1_dx dd 0  ;ширина изображения-оригинала
img1_dy dd 0  ;высота изображения-оригинала
img1_filename db "img1.bmp",0 ;имя файла, содержащего картинку

texture1 dd 0 ;указатель на текстуру в формате OpenGL
t1_dx dd 256  ;ширина текстуры (согласно документации должна быть степенью 2)
t1_dy dd 256  ;высота текстуры (согласно документации должна быть степенью 2)

;кнопка "Выход"
btnclass db "BUTTON",0
btn_quit_caption db "Quit",0
btn_quit_hwnd dd 0

;кнопка "Рисовать"
btn_draw_caption db "Draw",0
btn_draw_hwnd dd 0

;окно графического вывода (аналог PaintBox в Delphi)
;в качестве полотна используется кнопка типа GroupBox
paint_caption db "OpenGL output window",0
paint_hwnd dd 0
paint_hdc dd 0
paint_hrc dd 0
paint_dx dd 300
paint_dy dd 300
paint_dx_q dq 300.0 ;т.к. функция gluOrtho2D OpenGL использует вещественные
paint_dy_q dq 300.0 ;аргументы, то зададим их непосредственно здесь
;===============================

segment .code use 32
_main:
   push ebp
   mov ebp,esp
;================
regclass:	
	mov dword [wc+WNDCLASSEX.cbSize],48
	mov dword [wc+WNDCLASSEX.style],CS_HREDRAW+CS_VREDRAW+CS_GLOBALCLASS
	mov dword [wc+WNDCLASSEX.lpfnWndProc],winproc
	mov dword [wc+WNDCLASSEX.cbClsExtra],0
        mov dword [wc+WNDCLASSEX.cbWndExtra],0

	call _GetModuleHandleA@4
	mov dword [wc+WNDCLASSEX.hInstance],eax
	
	push dword IDI_APPLICATION
	push dword 0
	call _LoadIconA@8
	mov dword [wc+WNDCLASSEX.hIcon],eax

	push dword IDC_ARROW
	push dword 0
	call _LoadCursorA@8
	mov dword [wc+WNDCLASSEX.hCursor],eax
	
	push dword 0
	mov eax,COLOR_WINDOW
	mov dword [wc+WNDCLASSEX.hbrBackground],eax
	mov dword [wc+WNDCLASSEX.lpszMenuName],0
	mov dword [wc+WNDCLASSEX.lpszClassName],winclass

	push dword IDI_APPLICATION
	push dword 0
	call _LoadIconA@8
	mov dword [wc+WNDCLASSEX.hIconSm],eax

	push dword wc
	call _RegisterClassExA@4

;Создание окна зарегистрированного класса
	push dword 0
	push dword [wc+WNDCLASSEX.hInstance]
	push dword 0
	push dword 0
	push dword 350
	push dword 450
	push dword 100
	push dword 100
	push dword WS_OVERLAPPEDWINDOW
	push dword progtitle
	push dword winclass
	push dword 0
	call _CreateWindowExA@48

	cmp eax,0
	je near .exitprog

	mov dword [winhwnd],eax
	push dword SW_SHOWNORMAL
	push dword eax
	call _ShowWindow@8
	push dword [winhwnd]
	call _UpdateWindow@4

;Цикл обработки сообщений
.msgloop:
	push dword 0
	push dword 0
	push dword 0
	push dword msg
	call _GetMessageA@16
	
	cmp eax,0
	je near .exitprog
	
	push dword msg
	call _TranslateMessage@4
	push dword msg
	call _DispatchMessageA@4
	jmp near .msgloop

;Точка выхода из программы
.exitprog:
	mov esp,ebp
        pop ebp
        ret

;===============================
;оконная процедура
; ebp+20 - lparam
; ebp+16 - wparam
; ebp+12 - msg
; ebp+8  - hwnd
winproc:
	push ebp
	mov ebp,esp
;===============================
	cmp dword [ebp+12], WM_DESTROY
	je near .wmdestroy
	cmp dword [ebp+12], WM_CREATE
	je near .wmcreate
;===============================
	cmp dword [ebp+12], WM_COMMAND
	je near .wmcommand
;===============================
;Обработчики сообщений
.default:
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword [ebp+8]
	call _DefWindowProcA@16 ;Обработчик сообщений по умолчанию
	jmp near .finish
;===============================
.wmcommand:
;обработчик кнопки Quit
	mov dword eax,[btn_quit_hwnd] ;сравниваем хэндл кнопки
	cmp dword [ebp+20],eax    ;с lParam сообщения
	je near .wmdestroy        ;если совпали, то выходим
;обработчик кнопки Draw
	mov dword eax,[btn_draw_hwnd] ;сравниваем хэндл кнопки
	cmp dword [ebp+20],eax    ;с lParam сообщения
	jne near .command_finish  ;если не совпали, то выходим
	;-------------------
	call DrawScene  ;вызываем функцию рисования на полотне
	;-------------------
.command_finish:
	jmp near .finish

;===============================
.wmcreate:
;создание кнопки "выход"
	push dword btn_quit_caption
	push dword 20 ;[dy]
	push dword 70 ;[dx]
	push dword 10 ;[y]
	push dword 10 ;[x]
	push dword [ebp+8]	
	call MakeButton
	add dword esp,24
	mov dword [btn_quit_hwnd],eax

;создание кнопки "рисовать"
	push dword btn_draw_caption
	push dword 20 ;[dy]
	push dword 70 ;[dx]
	push dword 40 ;[y]
	push dword 10 ;[x]
	push dword [ebp+8]	
	call MakeButton
	add dword esp,24
	mov dword [btn_draw_hwnd],eax

;создание окна графического вывода
	push dword paint_caption
	push dword [paint_dy] ;[dy]
	push dword [paint_dx] ;[dx]
	push dword 10  ;[y]
	push dword 100 ;[x]
	push dword [ebp+8]	
	call MakeGroupBox
	add dword esp,24
	mov dword [paint_hwnd],eax

;инициализация графической подсистемы OPENGL
	push dword 40
	push dword 0
	push dword pfd
	call _memset   ;memset(&pfd,0,sizeof(pfd));

	push dword [paint_hwnd]
	call _GetDC@4
	mov dword [paint_hdc],eax ;hdc=GetDC(paint_hwnd);

	push dword pfd
	push dword [paint_hdc]
	call _ChoosePixelFormat@8
	mov dword [nPixelFormat],eax ;nPixelFormat=ChoosePixelFormat(hdc,&pfd);

	push dword pfd
	push dword [nPixelFormat]
	push dword [paint_hdc]
	call _SetPixelFormat@12  ;SetPixelFormat(hdc,nPixelFormat,&pfd);

	push dword [paint_hdc]
	call _wglCreateContext@4
	mov dword [paint_hrc],eax ;hrc=wglCreateContext(hdc);

	push dword [paint_hrc]	
	push dword [paint_hdc]
	call _wglMakeCurrent@8  ;wglMakeCurrent(hdc,hrc);
	
	push dword GL_PROJECTION
	call _glMatrixMode@4    ;glMatrixMode(GL_PROJECTION);
	
	call _glLoadIdentity@0  ;glLoadIdentity();
	
	push dword [paint_dy_q+4]
	push dword [paint_dy_q]
	push dword [q_zero+4]
	push dword [q_zero]
	push dword [paint_dx_q+4]
	push dword [paint_dx_q]
	push dword [q_zero+4]
	push dword [q_zero]
	call _gluOrtho2D@32    ;gluOrtho2D(0,windW,0,windH);
	
	push dword GL_MODELVIEW
	call _glMatrixMode@4   ;glMatrixMode(GL_MODELVIEW);
	
	push dword [f_zero] ;Alpha
	push dword [f_one]  ;Blue
	push dword [f_one]  ;Green
	push dword [f_one]  ;Red
	call _glClearColor@16  ;glClearColor(1,1,1,0);

;загрузка файла формата BMP 24bpp в память
	push dword img1_dy
	push dword img1_dx
	push dword img1_filename
	call LoadFromBMP
	mov dword [img1],eax ;содержит потенциальную опасность если файла нет

;подготовка текстуры для будущего использования
	push dword [t1_dy]
	push dword [t1_dx]
	push dword texture1
	push dword [img1_dy]
	push dword [img1_dx]
	push dword [img1]
	call MakeTexture

	jmp near .finish
;===============================
.wmdestroy:
	push dword 0
	push dword 0
	call _wglMakeCurrent@8

	push dword [paint_hrc]
	call dword _wglDeleteContext@4

	push dword [paint_hdc]
	call _DeleteDC@4

	push dword img1
	call _free

	push dword texture1
	call _free

	push dword 0
	call _PostQuitMessage@4
	mov dword eax,0
	jmp near .finish

.finish:
	mov esp,ebp
	pop ebp
	ret

;===============================
;создание кнопки
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeButton:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+BS_DEFPUSHBUTTON+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;создание окна группы
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeGroupBox:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword BS_GROUPBOX+ES_READONLY+WS_VISIBLE+WS_TABSTOP+WS_BORDER+WS_CHILD
; + WS_CLIPCHILDREN + WS_CLIPSIBLINGS если следовать официальной документации OpenGL
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
