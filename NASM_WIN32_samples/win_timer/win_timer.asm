BITS 32

%include "win_timer.inc"
%include "inc/messages.inc"
%include "inc/winstyles.inc"
%include "inc/gl.inc"
%include "inc/glu.inc"
%include "inc/f_const.inc"
%include "inc/d_const.inc"

global _main     ;�窠 �室� � �ணࠬ��

global img1    ;㪠��⥫� �� ���⨭�� � ����ࠦ����� ⥪�����
global img1_dx ;�ਭ� ����ࠦ���� ��� ⥪�����
global img1_dy ;���� ����ࠦ���� ��� ⥪�����

global texture1 ;㪠��⥫� �� ⥪����� � �ଠ� OpenGL
global t1_dx ;�ਭ� ⥪�����
global t1_dy ;���� ⥪�����

global _theta
global _phi
global _dist

extern DrawScene   ;������ ��楤�� �ᮢ����
extern LoadFromBMP ;��楤�� ����㧪� 䠩�� � �ଠ� BMP 24bpp
extern MakeTexture ;��楤�� �८�ࠧ������ ���⨭�� � �ଠ� ⥪����� OpenGL

segment .stack use 32
stack times 1000 db 0

segment .data use 32
wc times 12 dd 0  ;����� �������� ����
msg times 6 dd 0  ;ᮮ�饭��, ��।������ �ணࠬ�� �� Windows
pfd times 40 db 0 ;����⥫� �ଠ� ��䨪� (PixelFormatDescriptor)
nPixelFormat dd 0 ;��筥��� �ଠ� ��䨪�

_light0_pos  dd 0.0,100.0,0.0,1.0
_light0_dir  dd 0.0,1.0,0.0
_diffuse0    dd 1.0,1.0,1.0,0.0
_ambient0    dd 1.0,1.0,1.0,0.0
_specular0   dd 1.0,1.0,1.0,1.0
_global_ambient dd 0.3,0.3,0.3,1.0

_theta	dd -150.0
_phi	dd 0.0
_dist	dd -300.0

winclass db "CLASS32",0
winhwnd dd 0
progtitle db "Win_timer",0
fmt_dec db "%d",13,10,0

;-------------------------------------------------------
img1 dd 0     ;㪠��⥫� �� ᮤ�ন��� ����᪮�� 䠩�� BMP 24bpp
img1_dx dd 0  ;�ਭ� ����ࠦ����-�ਣ�����
img1_dy dd 0  ;���� ����ࠦ����-�ਣ�����
img1_filename db "img1.bmp",0 ;��� 䠩��, ᮤ�ঠ饣� ���⨭��

texture1 dd 0 ;㪠��⥫� �� ⥪����� � �ଠ� OpenGL
t1_dx dd 256  ;�ਭ� ⥪����� (ᮣ��᭮ ���㬥��樨 ������ ���� �⥯���� 2)
t1_dy dd 256  ;���� ⥪����� (ᮣ��᭮ ���㬥��樨 ������ ���� �⥯���� 2)

;������ "��室"
btnclass db "BUTTON",0
btn_quit_caption db "Quit",0
btn_quit_hwnd dd 0

;���� ����᪮�� �뢮�� (������ PaintBox � Delphi)
;� ����⢥ ����⭠ �ᯮ������ ������ ⨯� GroupBox
paint_caption db "OpenGL output window",0
paint_hwnd dd 0
paint_hdc dd 0
paint_hrc dd 0
paint_dx dd 300
paint_dy dd 300
paint_dx_q dq 300.0 ;�.�. �㭪�� gluOrtho2D OpenGL �ᯮ���� ����⢥���
paint_dy_q dq 300.0 ;��㬥���, � ������� �� �����।�⢥��� �����
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

;�������� ���� ��ॣ����஢������ �����
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

;���� ��ࠡ�⪨ ᮮ�饭��
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

;��窠 ��室� �� �ணࠬ��
.exitprog:
	mov esp,ebp
        pop ebp
        ret

;===============================
;������� ��楤��
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
	cmp dword [ebp+12], WM_TIMER
	je near .wmtimer
;===============================
;��ࠡ��稪� ᮮ�饭��
.default:
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword [ebp+8]
	call _DefWindowProcA@16 ;��ࠡ��稪 ᮮ�饭�� �� 㬮�砭��
	jmp near .finish
;===============================
.wmcommand:
;��ࠡ��稪 ������ Quit
	mov dword eax,[btn_quit_hwnd] ;�ࠢ������ ��� ������
	cmp dword [ebp+20],eax    ;� lParam ᮮ�饭��
	je near .wmdestroy        ;�᫨ ᮢ����, � ��室��

	jmp near .finish
;===============================
.wmtimer:
	call DrawScene  ;��뢠�� �㭪�� �ᮢ���� �� ����⭥
	jmp near .finish
;===============================
.wmcreate:
;�������� ⠩���
	push dword 0
	push dword 100    ;���ࢠ� � �����ᥪ㭤��
	push dword 1       ;����� ⠩���
	push dword [ebp+8] ;hwnd
	call _SetTimer@16

;ᮧ����� ������ "��室"
	push dword btn_quit_caption
	push dword 20 ;[dy]
	push dword 70 ;[dx]
	push dword 10 ;[y]
	push dword 10 ;[x]
	push dword [ebp+8]	
	call MakeButton
	add dword esp,24
	mov dword [btn_quit_hwnd],eax

;ᮧ����� ���� ����᪮�� �뢮��
	push dword paint_caption
	push dword [paint_dy] ;[dy]
	push dword [paint_dx] ;[dx]
	push dword 10  ;[y]
	push dword 100 ;[x]
	push dword [ebp+8]	
	call MakeGroupBox
	add dword esp,24
	mov dword [paint_hwnd],eax

;���樠������ ����᪮� �����⥬� OPENGL
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
	

	push dword GL_LIGHTING
	call _glEnable@4

	push dword _global_ambient
	push dword GL_LIGHT_MODEL_AMBIENT
	call _glLightModelfv@8

	push dword _light0_pos
	push dword GL_POSITION
	push dword GL_LIGHT0
	call _glLightfv@12

	push dword _light0_dir
	push dword GL_SPOT_DIRECTION
	push dword GL_LIGHT0
	call _glLightfv@12

	push dword _ambient0
	push dword GL_AMBIENT
	push dword GL_LIGHT0
	call _glLightfv@12

	push dword _diffuse0
	push dword GL_DIFFUSE
	push dword GL_LIGHT0
	call _glLightfv@12

	push dword _specular0
	push dword GL_SPECULAR
	push dword GL_LIGHT0
	call _glLightfv@12

	push dword GL_LIGHT0
	call _glEnable@4

	push dword [paint_dy]
	push dword [paint_dx]
	push dword 0
	push dword 0
	call _glViewport@16 ;glViewport(0,0,windW,windH);

	push dword GL_PROJECTION
	call _glMatrixMode@4    ;glMatrixMode(GL_PROJECTION);
	
	call _glLoadIdentity@0  ;glLoadIdentity();
	
	push dword [d_1000+4]
	push dword [d_1000]
	push dword [d_1p0+4]
	push dword [d_1p0]
	push dword [d_1p5+4]
	push dword [d_1p5]
	push dword [d_60+4]
	push dword [d_60]
	call _gluPerspective@32 ;gluPerspective(60,1.5,1.0,1000);
	
	push dword GL_MODELVIEW
	call _glMatrixMode@4   ;glMatrixMode(GL_MODELVIEW);

	push dword [_dist] ;dz
	push dword [f_00]   ;dy
	push dword [f_00]   ;dx
	call _glTranslatef@12

	push dword [f_0p0] ;vz
	push dword [f_0p0] ;vy
	push dword [f_1p0] ;vx
	push dword [_theta] ;alpha
	call _glRotatef@16
	           
	push dword [f_0p0] ;vz
	push dword [f_1p0] ;vy
	push dword [f_0p0] ;vx
	push dword [_phi] ;alpha
	call _glRotatef@16
	
	push dword [f_0p0] ;Alpha
	push dword [f_0p0] ;Blue
	push dword [f_0p0] ;Green
	push dword [f_0p0] ;Red
	call _glClearColor@16

;����㧪� 䠩�� �ଠ� BMP 24bpp � ������
	push dword img1_dy
	push dword img1_dx
	push dword img1_filename
	call LoadFromBMP
	mov dword [img1],eax ;ᮤ�ন� ��⥭樠���� ���᭮��� �᫨ 䠩�� ���

;�����⮢�� ⥪����� ��� ���饣� �ᯮ�짮�����
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
	;㭨�⮦��� ⠩���
	push dword 1       ;����� ⠩���
	push dword [ebp+8] ;hwnd
	call _KillTimer@8

	push dword 0
	push dword 0
	call _wglMakeCurrent@8

	push dword [paint_hrc]
	call _wglDeleteContext@4

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
;ᮧ����� ������
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
;ᮧ����� ���� ��㯯�
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
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
