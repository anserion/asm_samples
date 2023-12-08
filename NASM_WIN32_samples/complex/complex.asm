global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use 32
;--------------------------------
;���塞 �������� complex
;--------------------------------
struc complex
.re resd 1
.im resd 1
endstruc
;--------------------------------

;--------------------------------
;���樠�����㥬 ��६���� a,b,c
;�������� �������� complex
;--------------------------------
a istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend

b istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend

c istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend
;--------------------------------

intro_msg db "�ணࠬ�� ᫮����� � ���⠭�� ���������� �ᥫ",13,10,0
exit_msg db "������ ���� ������ �� ��������� ��� ��室�",13,10,0

mess_a_re db "a.re= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a
mess_a_im db "a.im= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a

mess_b_re db "b.re= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� b
mess_b_im db "b.im= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� b

fmt_str db "%d",0 ;�ଠ������ ��ப� ��� 楫��� �᫠


otv1 db "�⢥�: a+b= %d + i* %d",13,10,0
otv2 db "�⢥�: a-b= %d + i* %d",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword intro_msg
   call _printf
   add dword esp,4
;�뢮� ᮮ�饭�� "a.re="
   push dword mess_a_re
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� a.re
   push dword a+complex.re
   push dword fmt_str
   call _scanf
   add dword esp,8
;�뢮� ᮮ�饭�� "a.im="
   push dword mess_a_im
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� a.im
   push dword a+complex.im
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;�뢮� ᮮ�饭�� "b.re="
   push dword mess_b_re
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� b.re
   push dword b+complex.re
   push dword fmt_str
   call _scanf
   add dword esp,8
;�뢮� ᮮ�饭�� "b.im="
   push dword mess_b_im
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� b.im
   push dword b+complex.im
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;᫮����� ���������� �ᥫ
   mov dword eax,[a+complex.re]
   add dword eax,[b+complex.re]
   mov dword [c+complex.re],eax

   mov dword eax,[a+complex.im]
   add dword eax,[b+complex.im]
   mov dword [c+complex.im],eax
;---------------------------
;�뢮� �⢥� ᫮����� ���������� �ᥫ
   push dword [c+complex.im]
   push dword [c+complex.re]
   push dword otv1
   call _printf
   add dword esp,12
;---------------------------
;���⠭�� ���������� �ᥫ
   mov dword eax,[a+complex.re]
   sub dword eax,[b+complex.re]
   mov dword [c+complex.re],eax

   mov dword eax,[a+complex.im]
   sub dword eax,[b+complex.im]
   mov dword [c+complex.im],eax
;---------------------------
;�뢮� �⢥� ���⠭�� ���������� �ᥫ
   push dword [c+complex.im]
   push dword [c+complex.re]
   push dword otv2
   call _printf
   add dword esp,8
;----------------------------
;����প� �뢮�� �� ������ �� ������
   push dword exit_msg
   call _printf
   add dword esp,4
   call _getch
;==========================
   mov esp,ebp
   pop ebp
ret
