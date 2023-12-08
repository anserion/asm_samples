BITS 32
%include "gl.inc"
%include "glu.inc"

global DrawScene  ;Внешняя процедура рисования
global PrepareTexture ;включение текущей текстуры из возможных нескольких
global MakeTexture ;процедура преобразования картинки в формат текстуры OpenGL

extern img1     ;указатель на картинку с изображением текстуры
extern img1_dx  ;ширина изображения для текстуры
extern img1_dy  ;высота изображения для текстуры

extern texture1 ;указатель на текстуру в формате OpenGL
extern t1_dx    ;ширина текстуры
extern t1_dy    ;высота текстуры

extern _malloc
extern _printf
extern _creat
extern _close
extern _write

extern _glClear@4    ;функция очистки графического полотна
extern _glColor3f@12 ;установка цвета рисования
extern _glVertex2i@8 ;указание создания базового примитива Vertex
extern _glVertex2f@8 ;указание создания базового примитива Vertex
extern _glTexCoord2i@8 ;указание точки на карте текстуры
extern _glTexCoord2f@8 ;указание точки на карте текстуры
extern _glBegin@4    ;команда начала загрузки вертексов в конвейер OpenGL
extern _glEnd@0      ;команда завершения загрузки вертексов в конвейер OpenGL
extern _glFinish@0   ;команда синхронной обработки конвейеров (рендеринг)
extern _glEnable@4   ;команда включения различных расширений OpenGL
extern _glDisable@4  ;команда выключения различных расширений OpenGL
extern _glTexParameteri@12 ;команда управления активации текстуры
extern _glTexImage2D@36 ;команда включения текущей текстуры
extern _glTexEnvi@12 ;команда управления взаимодействием текстуры и фона
extern _gluScaleImage@36 ;команда аппаратного масштабирования изображения

segment .stack use 32
stack times 1000 db 0

segment .data use 32
f_00 	dd 0.0 ;так как большинство команд OpenGL манипулируют
f_01 	dd 0.1 ;с вещественными аргументами, то чтобы
f_02 	dd 0.2 ;не загружать сопроцессор зададим
f_03 	dd 0.3 ;последовательность часто используемых
f_04 	dd 0.4 ;вещественных чисел непосредственно
f_05 	dd 0.5 ;в сегменте данных
f_06 	dd 0.6
f_07 	dd 0.7
f_08 	dd 0.8
f_09 	dd 0.9
f_10 	dd 1.0
;--------------
x1	dd 0.0
y1	dd 200.0

x2	dd 200.0
y2	dd 200.0

x3	dd 200.0
y3	dd 300.0

x4	dd 0.0
y4	dd 300.0
;--------------
t_x1	dd 0.0
t_y1	dd 0.0

t_x2	dd 1.0
t_y2	dd 0.0

t_x3	dd 1.0
t_y3	dd 1.0

t_x4	dd 0.0
t_y4	dd 1.0
;===========================================================
segment .code use 32

;формирование текстуры в памяти ЭВМ на основе готового изображения
;ebp+28 - texture_dy
;ebp+24 - texture_dx
;ebp+20 - *texture
;ebp+16 - img_dy
;ebp+12 - img_dx
;ebp+8  - *img
MakeTexture:
	push ebp
	mov ebp,esp
	;----------------------------
	mov dword eax,[ebp+24]
	xor edx,edx
	mul dword [ebp+28]
	mov dword ebx,3
	xor edx,edx
	mul dword ebx ;eax=texture_dx*texture_dy*3;

	push dword eax
	call _malloc
	mov dword ebx,[ebp+20]
	mov dword [ebx],eax ;texture=malloc(eax);

	mov dword eax,[ebp+20]
	push dword [eax]
	push dword GL_UNSIGNED_BYTE
	push dword [ebp+28]
	push dword [ebp+24]
	push dword [ebp+8]
	push dword GL_UNSIGNED_BYTE
	push dword [ebp+16]
	push dword [ebp+12]
	push dword GL_RGB
	call _gluScaleImage@36

        ;----------------------------
	mov esp,ebp
	pop ebp
	ret

;----------------------------
;включение текущей текстуры из возможных нескольких
;ebp+16 - texture_dy
;ebp+12 - texture_dx
;ebp+8  - *texture
PrepareTexture:
	push ebp
	mov ebp,esp
	;----------------------------
	push dword GL_NEAREST
	push dword GL_TEXTURE_MAG_FILTER
	push dword GL_TEXTURE_2D
	call _glTexParameteri@12

	push dword GL_NEAREST
	push dword GL_TEXTURE_MIN_FILTER
	push dword GL_TEXTURE_2D
	call _glTexParameteri@12

	push dword [ebp+8]
	push dword GL_UNSIGNED_BYTE
	push dword GL_RGB
	push dword 0
	push dword [ebp+16]
	push dword [ebp+12]
	push dword 3
	push dword 0
	push dword GL_TEXTURE_2D
	call _glTexImage2D@36

	push dword GL_DECAL
	push dword GL_TEXTURE_ENV_MODE
	push dword GL_TEXTURE_ENV
	call _glTexEnvi@12
        ;----------------------------
	mov esp,ebp
	pop ebp
	ret

;----------------------------
DrawScene:
	push ebp
	mov ebp,esp
;----------------------------
	;очистим полотно
	push dword GL_COLOR_BUFFER_BIT
	call _glClear@4
;----------------------------

	;установим цвет рисования (1,0,0) - чисто красный
	push dword [f_00]  ; B
	push dword [f_00]  ; G
	push dword [f_10]  ; R
	call _glColor3f@12
;----------------------------
	;загрузим в конвейер OpenGL вертексы рисования точек
	push dword GL_POINTS
	call _glBegin@4

	push dword 50 ;y
	push dword 250 ;x
	call _glVertex2i@8

	push dword 51 ;y
	push dword 250 ;x
	call _glVertex2i@8

	push dword 52 ;y
	push dword 250 ;x
	call _glVertex2i@8

	push dword 51 ;y
	push dword 251 ;x
	call _glVertex2i@8

	call _glEnd@0
;----------------------------
	;установим цвет рисования (0,1,0) - чисто зеленый
	push dword [f_00]  ; B
	push dword [f_10]  ; G
	push dword [f_00]  ; R
	call _glColor3f@12
;----------------------------
	;загрузим в конвейер OpenGL вертексы рисования отрезков
	push dword GL_LINES
	call _glBegin@4

	push dword 100 ;y1
	push dword 150 ;x1
	call _glVertex2i@8

	push dword 110 ;y2
	push dword 250 ;x2
	call _glVertex2i@8

	call _glEnd@0
;----------------------------
	;установим цвет рисования (1,0.5,0.3) - ближе к красному, чем синему
	push dword [f_03]  ; B
	push dword [f_05]  ; G
	push dword [f_10]  ; R
	call _glColor3f@12
;----------------------------
	;загрузим в конвейер OpenGL вертексы рисования треугольников
	push dword GL_TRIANGLES
	call _glBegin@4

	push dword 120 ;y1
	push dword 150 ;x1
	call _glVertex2i@8

	push dword 190 ;y2
	push dword 150 ;x2
	call _glVertex2i@8

	push dword 200 ;y3
	push dword 230 ;x3
	call _glVertex2i@8

	call _glEnd@0
;----------------------------
	;установим цвет рисования (1,0.4,1)
	push dword [f_10]  ; B
	push dword [f_04]  ; G
	push dword [f_10]  ; R
	call _glColor3f@12
;----------------------------
	;загрузим в конвейер OpenGL вертексы рисования четырехугольников
	push dword GL_QUADS
	call _glBegin@4

	push dword 10 ;y1
	push dword 10 ;x1
	call _glVertex2i@8

	push dword 10 ;y2
	push dword 100 ;x2
	call _glVertex2i@8

	push dword 150 ;y3
	push dword 100 ;x3
	call _glVertex2i@8

	push dword 150 ;y4
	push dword 10 ;x4
	call _glVertex2i@8

	call _glEnd@0
;----------------------------
	;демонстрация плавного перехода цвета :)
	push dword GL_TRIANGLES
	call _glBegin@4
	;установим цвет первой вершины
	push dword [f_10]  ; B
	push dword [f_00]  ; G
	push dword [f_10]  ; R
	call _glColor3f@12
	;поместим в конвейер координаты первой вершины
	push dword 50 ;y1
	push dword 150 ;x1
	call _glVertex2i@8

	;установим цвет второй вершины
	push dword [f_10]  ; B
	push dword [f_10]  ; G
	push dword [f_00]  ; R
	call _glColor3f@12
	;поместим в конвейер координаты второй вершины
	push dword 70 ;y2
	push dword 240 ;x2
	call _glVertex2i@8

	;установим цвет третьей вершины
	push dword [f_00]  ; B
	push dword [f_10]  ; G
	push dword [f_10]  ; R
	call _glColor3f@12
	;поместим в конвейер координаты третьей вершины
	push dword 10 ;y3
	push dword 180 ;x3
	call _glVertex2i@8

	call _glEnd@0
;----------------------------
	;теперь даем синхронную команду рисования содержимого конвейера OpenGL
	call _glFinish@0
;----------------------------
;вывод текстуры %)~
	;включаем режим текстурирования
	push dword GL_TEXTURE_2D
	call _glEnable@4
	;активизируем текстуру texture1
	push dword [t1_dy]
	push dword [t1_dx]
	push dword [texture1]
	call PrepareTexture

	;будем накладывать текстуру на четырехугольник
	push dword GL_QUADS
	call _glBegin@4

	;первая вершина
	push dword [t_y1] ;y1
	push dword [t_x1] ;x1
	call _glTexCoord2f@8
	
	push dword [y1] ;y1
	push dword [x1] ;x1
	call _glVertex2f@8

        ;вторая вершина
	push dword [t_y2] ;y2
	push dword [t_x2] ;x2
	call _glTexCoord2f@8

	push dword [y2] ;y2
	push dword [x2] ;x2
	call _glVertex2f@8

	;третья вершина
	push dword [t_y3] ;y3
	push dword [t_x3] ;x3
	call _glTexCoord2f@8

	push dword [y3] ;y3
	push dword [x3] ;x3
	call _glVertex2f@8

        ;четвертая вершина
	push dword [t_y4] ;y4
	push dword [t_x4] ;x4
	call _glTexCoord2f@8

	push dword [y4] ;y4
	push dword [x4] ;x4
	call _glVertex2f@8

	call _glEnd@0

	;выключаем режим текстурирования
	push dword GL_TEXTURE_2D
	call _glDisable@4
;----------------------------
	;теперь даем синхронную команду рисования содержимого конвейера OpenGL
	call _glFinish@0

	mov esp,ebp
	pop ebp
	ret
