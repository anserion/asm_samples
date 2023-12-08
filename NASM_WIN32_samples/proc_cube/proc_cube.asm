global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0 ;������ ��� ��६����� a
mess_a db "a= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a
fmt_a db "%d",0   ;a - 楫�� �᫮

otv1 db "�⢥�: a^3= %d",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� "a="
   push dword mess_a
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� a
   push dword a
   push dword fmt_a
   call _scanf
   add dword esp,8
;���� �㡠 �᫠ a
   push dword [a]
   call cube
   add esp,4
;�뢮� �⢥� (�⢥� � eax)
   push dword eax
   push dword otv1
   call _printf
   add esp,8
;����প� ��। ��室��
  call _getch
;==========================
   mov esp,ebp
   pop ebp
ret

;����ணࠬ�� ���� �㡠 �᫠
; ebx=[x];
; eax=ebx; edx=0;
; eax=eax*ebx;
; eax=eax*ebx;
; return eax
cube:
   ;ebp+8 - [x]
   push dword ebp ;�⠭����� �室 � ����ணࠬ��
   mov ebp,esp
;---------------
   mov dword ebx,[ebp+8]  ;ebx=[x]
   mov eax,ebx            ;eax=ebx
   xor edx,edx            ;edx=0
   mul dword ebx          ;eax=eax*ebx
   mul dword ebx          ;eax=eax*ebx
;---------------
   mov esp,ebp ;�⠭����� ��室 �� ����ணࠬ��
   pop ebp
ret