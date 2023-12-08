global _main
extern _printf
extern _scanf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0 ;������ ��� ��६����� a
b dd 0 ;������ ��� ��६����� b
c dd 0 ;������ ��� ��६����� c
r dd 0 ;������ ��� ��६����� r

mess_a db "a= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a
fmt_a db "%d",0   ;a - 楫�� �᫮

mess_b db "b= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� b
fmt_b db "%d",0   ;b - 楫�� �᫮

otv1 db "�⢥�: a+b= %d",13,10,0
otv2 db "�⢥�: a-b= %d",13,10,0
otv3 db "�⢥�: a*b= %d",13,10,0
otv4 db "�⢥�: a/b= %d (���⮪ %d)",13,10,0

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
;---------------------------
;�뢮� ᮮ�饭�� "b="
   push dword mess_b
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� b
   push dword b
   push dword fmt_b
   call _scanf
   add dword esp,8
;---------------------------
;᫮�����
   mov dword eax,[a]
   add dword eax,[b]
   mov dword [c],eax
;---------------------------
;�뢮� �⢥� ᫮�����
   push dword [c]
   push dword otv1
   call _printf
   add dword esp,8
;---------------------------
;���⠭��
   mov dword eax,[a]
   sub dword eax,[b]
   mov dword [c],eax
;---------------------------
;�뢮� �⢥� ���⠭��
   push dword [c]
   push dword otv2
   call _printf
   add dword esp,8
;---------------------------
;㬭������
   mov dword eax,[a]
   mov dword edx,0
   mul dword [b]
   mov dword [c],eax
;---------------------------
;�뢮� �⢥� 㬭������
   push dword [c]
   push dword otv3
   call _printf
   add dword esp,8
;---------------------------
;�������
   mov dword eax,[a]
   mov dword edx,0
   div dword [b]
   mov dword [c],eax
   mov dword [r],edx
;---------------------------
;�뢮� �⢥� �������
   push dword [r]
   push dword [c]
   push dword otv4
   call _printf
   add dword esp,12
;==========================
   mov esp,ebp
   pop ebp
ret
