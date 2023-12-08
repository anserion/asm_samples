BITS 32

extern _malloc
%include "inc/gl.inc"
%include "inc/glu.inc"
%include "inc/f_const.inc"
%include "inc/d_const.inc"

global DrawScene  ;Внешняя процедура рисования
global PrepareTexture ;включение текущей текстуры из возможных нескольких
global MakeTexture ;процедура преобразования картинки в формат текстуры OpenGL

extern img1     ;указатель на картинку с изображением текстуры
extern img1_dx  ;ширина изображения для текстуры
extern img1_dy  ;высота изображения для текстуры

extern texture1 ;указатель на текстуру в формате OpenGL
extern t1_dx    ;ширина текстуры
extern t1_dy    ;высота текстуры

extern _dist
extern _theta
extern _phi

segment .stack use 32
stack times 1000 db 0

segment .data use 32
_global_color dd 0.0,0.0,0.0
;--------------
x1	dd 0.0
y1	dd 200.0

x2	dd 200.0
y2	dd 200.0

x3	dd 200.0
y3	dd 300.0

x4	dd 0.0
y4	dd 300.0
;===========================================================
segment .code use 32

;ebp+16 - blue
;ebp+12 - green
;ebp+8  - red
set_color:
	push ebp
	mov ebp,esp
        ;----------------------------
	push dword [ebp+8]
	pop dword [_global_color]

	push dword [ebp+12]
	pop dword [_global_color+4]

	push dword [ebp+16]
	pop dword [_global_color+8]

	push dword _global_color
	push dword GL_DIFFUSE
	push dword GL_FRONT_AND_BACK
	call _glMaterialfv@12
        ;----------------------------
	mov esp,ebp
	pop ebp
	ret

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
	push dword GL_COLOR_BUFFER_BIT+GL_DEPTH_BUFFER_BIT
	call _glClear@4

	push dword GL_DEPTH_TEST
	call _glEnable@4

	push dword GL_LESS
	call _glDepthFunc@4

	push dword GL_SMOOTH
	call _glShadeModel@4

	push dword GL_FILL
	push dword GL_FRONT_AND_BACK
	call _glPolygonMode@8
;----------------------------
;поворот сцены
	push dword [f_0p0] ;vz
	push dword [f_1p0] ;vy
	push dword [f_0p0] ;vx
	push dword [f_05] ;alpha
	call _glRotatef@16
;----------------------------
	;установим цвет рисования (1,0,0) - чисто красный
;	push dword [f_0p0]  ; B
;	push dword [f_0p0]  ; G
;	push dword [f_1p0]  ; R
;	call set_color
;----------------------------
	;включаем режим текстурирования
	push dword GL_TEXTURE_2D
	call _glEnable@4
	;активизируем текстуру texture1
	push dword [t1_dy]
	push dword [t1_dx]
	push dword [texture1]
	call PrepareTexture

	push dword GL_TRIANGLES
	call _glBegin@4
        ;-------------------
	;треугольник 1
	;-------------------
	;первая вершина
	push dword [f_0p0] ;y1
	push dword [f_0p0] ;x1
	call _glTexCoord2f@8

	push dword [f_m100] ;z
	push dword [f_00] ;y
	push dword [f_m100] ;x
	call _glVertex3f@12

	;вторая вершина
	push dword [f_0p0] ;y1
	push dword [f_1p0] ;x1
	call _glTexCoord2f@8

	push dword [f_m100] ;z
	push dword [f_00] ;y
	push dword [f_100] ;x
	call _glVertex3f@12

	;третья вершина
	push dword [f_1p0] ;y1
	push dword [f_1p0] ;x1
	call _glTexCoord2f@8

	push dword [f_100] ;z
	push dword [f_00] ;y
	push dword [f_100] ;x
	call _glVertex3f@12

	;-------------------
	;треугольник 2
	;-------------------
	;первая вершина
	push dword [f_0p0] ;y1
	push dword [f_0p0] ;x1
	call _glTexCoord2f@8

	push dword [f_m100] ;z
	push dword [f_00] ;y
	push dword [f_m100] ;x
	call _glVertex3f@12

	;вторая вершина
	push dword [f_1p0] ;y1
	push dword [f_1p0] ;x1
	call _glTexCoord2f@8

	push dword [f_100] ;z
	push dword [f_00] ;y
	push dword [f_100] ;x
	call _glVertex3f@12

	;третья вершина
	push dword [f_1p0] ;y1
	push dword [f_0p0] ;x1
	call _glTexCoord2f@8

	push dword [f_100] ;z
	push dword [f_00] ;y
	push dword [f_m100] ;x
	call _glVertex3f@12

	call _glEnd@0
;----------------------------
	;теперь даем синхронную команду рисования содержимого конвейера OpenGL
	call _glFinish@0

	mov esp,ebp
	pop ebp
	ret
