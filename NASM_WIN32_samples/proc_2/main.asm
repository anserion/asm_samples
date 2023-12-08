global _main
extern _printf
extern _scanf
extern _getch

extern formula
extern cube

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0 ;������ ��� ��६����� a
b dd 0 ;������ ��� ��६����� b
c dd 0 ;������ ��� ��६����� c
mess_a db "a= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a
mess_b db "b= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� b
fmt_dec db "%d",0  ;楫�� �᫮

otv1 db "�⢥�: a^3+b^3= %d",13,10,0

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
   push dword fmt_dec
   call _scanf
   add dword esp,8

;�뢮� ᮮ�饭�� "b="
   push dword mess_b
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� b
   push dword b
   push dword fmt_dec
   call _scanf
   add dword esp,8
;���� ���� c=a^3+b^3
   push dword c
   push dword [b]
   push dword [a]
   call formula
   add esp,12
;�뢮� �⢥� 
   push dword [c]
   push dword otv1
   call _printf
   add esp,8
;����প� ��। ��室��
  call _getch
;==========================
   mov esp,ebp
   pop ebp
ret
