BITS 32

global LoadFromBMP

%include "readbmp.inc"

segment .stack use 32
stack times 1000 db 0

segment .data use 32

segment .code use 32
;===========================================================
;ebp+16 - *height
;ebp+12 - *width
;ebp+8  - *filename
;ebp-4  - fd
;ebp-8  - buffer
;ebp-12 - dx
;ebp-16 - dy
;ebp-20 - mem_size
;ebp-24 - *image
LoadFromBMP:
	push ebp
	mov ebp,esp
	sub esp,24
	;------------------
	push dword 0
	push dword [ebp+8]
	call __open
	mov dword [ebp-4],eax  ;fd=open(filename,0);
	cmp eax, -1
	jne .load_file
	xor eax,eax
	jmp near .finish  ;if (fd== -1) return NULL;
.load_file:
	push dword 0
	push dword 12h
	push dword [ebp-4]
	call __lseek       ;lseek(fd,0x12,0);

	push dword 4
	lea eax,[ebp-8]
	push dword eax
	push dword [ebp-4]
	call __read        ;read(fd,&buffer,4);

	mov dword eax,[ebp-8]
	mov dword [ebp-12],eax ;dx= *buffer;
	;------------------------------

	push dword 0
	push dword 16h
	push dword [ebp-4]
	call __lseek       ;lseek(fd,0x16,0);

	push dword 4
	lea eax,[ebp-8]
	push dword eax
	push dword [ebp-4]
	call __read        ;read(fd,&buffer,4);

	mov dword eax,[ebp-8]
	mov dword [ebp-16],eax ;dy= *buffer;
	;------------------------------

	mov dword eax,[ebp-12]
	xor edx,edx
	mul dword [ebp-16]
	mov dword ebx,3
	xor edx,edx
	mul dword ebx
	mov dword [ebp-20],eax ;mem_size= dx*dy*3;

	push dword [ebp-20]
	call _malloc
	mov dword [ebp-24],eax ;image=malloc(mem_size);
	cmp eax,0
	je near .finish   ;if (image==NULL) .finish;

	push dword 0
	push dword 36h
	push dword [ebp-4]
	call __lseek       ;lseek(fd,0x36,0);

	push dword [ebp-20]
	push dword [ebp-24]
	push dword [ebp-4]
	call __read        ;read(fd,image,mem_size);

	push dword [ebp-4]
	call __close       ;close(fd);
	;------------------------
	;меняем порядок следования BGR на RGB
	mov dword ebx,[ebp-24] ;ebx= image
	mov ecx,0
.next:
	xor eax,eax
	mov byte al,[ebx]
	mov byte ah,[ebx+2]
	mov byte [ebx],ah
	mov byte [ebx+2],al

	add dword ebx,3
	add dword ecx,3

	cmp dword ecx,[ebp-20]
	jl near .next

	;------------------------
	mov dword eax,[ebp-12]
	mov ebx,[ebp+12]
	mov dword [ebx],eax ;*width=dx;

	mov dword eax,[ebp-16]
	mov ebx,[ebp+16]
	mov dword [ebx],eax ;*height=dy;
 	;------------------
.finish:
	mov dword eax,[ebp-24] ;return image;
	mov esp,ebp
	pop ebp
	ret
