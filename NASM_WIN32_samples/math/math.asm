global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
aa dd 0.0 ;������ ��� ����⢥���� ��६����� a ⨯� float
bb dd 0.0 ;������ ��� ����⢥���� ��६����� b ⨯� float

a dq 0.0 ;������ ��� ����⢥���� ��६����� a ⨯� double
b dq 0.0 ;������ ��� ����⢥���� ��६����� b ⨯� double
c dq 0.0 ;������ ��� ����⢥���� ��६����� c ⨯� double

x dd 0; ������ ��� 楫�� ��६����� x

mess_a db "a= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� a
mess_b db "b= ",0 ;⥪�� ᮮ�饭�� ��� ����� ���祭�� b
fmt_str db "%f",0 ;����⢥���� �᫮ float

otv_sum db "�⢥�: a+b= %f",13,10,0
otv_vic db "�⢥�: a-b= %f",13,10,0
otv_umn db "�⢥�: a*b= %f",13,10,0
otv_del db "�⢥�: a/b= %f",13,10,0
otv_neg db "�⢥�: -a= %f",13,10,0
otv_sqrt db "�⢥�: sqrt(a)= %f",13,10,0
otv_abs db "�⢥�: abs(a)= %f",13,10,0
otv_sin db "�⢥�: sin(a)= %f",13,10,0
otv_cos db "�⢥�: cos(a)= %f",13,10,0
otv_atan db "�⢥�: arctg(a/b)= %f",13,10,0
otv_log2 db "�⢥�: log2(a)= %f",13,10,0
otv_cel db "�⢥�: a(double)->x(int)=%d",13,10,0
otv_dbl db "�⢥�: x+1(int)->c(double)=%f",13,10,0

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
   push dword aa
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;�뢮� ᮮ�饭�� "b="
   push dword mess_b
   call _printf
   add dword esp,4
;���� ���祭�� ��६����� b
   push dword bb
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;���樠������ ᮯ�����
   finit
;---------------------------
;��ॢ�� ��������� ���祭�� a � b �� float � double
   fld dword [aa]
   fst qword [a]

   fld dword [bb]
   fst qword [b]
;---------------------------
;᫮����� �� ᮯ�����
   fld qword [a]
   fadd qword [b]
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_sum
   call _printf
   add dword esp,12
;---------------------------
;���⠭�� �� ᮯ�����
   fld qword [a]
   fsub qword [b]
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_vic
   call _printf
   add dword esp,12
;---------------------------
;㬭������ �� ᮯ�����
   fld qword [a]
   fmul qword [b]
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_umn
   call _printf
   add dword esp,12
;---------------------------
;������� �� ᮯ�����
   fld qword [a]
   fdiv qword [b]
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_del
   call _printf
   add dword esp,12
;---------------------------
;��������� ����� �� ᮯ�����
   fld qword [a]
   fchs
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_neg
   call _printf
   add dword esp,12
;---------------------------
;���᫥��� ���� �����⭮�� �� ᮯ�����
   fld qword [a]
   fsqrt
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_sqrt
   call _printf
   add dword esp,12
;---------------------------
;��宦����� ����� (��᮫�⭮�� ���祭��) �� ᮯ�����
   finit
   fld qword [a]
   fabs
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_abs
   call _printf
   add dword esp,12
;---------------------------
;���᫥��� ᨭ�� �� ᮯ�����
   fld qword [a]
   fsin
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_sin
   call _printf
   add dword esp,12
;---------------------------
;���᫥��� ��ᨭ�� �� ᮯ�����
   fld qword [a]
   fcos
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_cos
   call _printf
   add dword esp,12
;---------------------------
;���᫥��� ��⠭���� �� ᮯ�����
   fld qword [a]
   fst st1
   fld qword [b]
   fpatan
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_atan
   call _printf
   add dword esp,12
;---------------------------
;���᫥��� �����䬠 �� �᭮����� 2 �� ᮯ�����
   fld1
   fst st1
   fld qword [a]
   fyl2x
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_log2
   call _printf
   add dword esp,12
;---------------------------
;�८�ࠧ������ �� ����⢥����� � 楫�� �� ᮯ�����
   fld qword [a]
   fist dword [x]
   fwait
;�뢮� �⢥�
   push dword [x]
   push dword otv_cel
   call _printf
   add dword esp,12
;---------------------------
;�८�ࠧ������ �� 楫��� � ����⢥���� �� ᮯ�����
;-----------
   mov dword eax,[x] ;���⮥ 㢥��祭��
   add eax,1         ;ᮤ�ন���� [x] �� 1
   mov dword [x],eax
;-----------
   fild dword [x]
   fst qword [c]
   fwait
;�뢮� �⢥�
   push dword [c+4]
   push dword [c]
   push dword otv_dbl
   call _printf
   add dword esp,12

;==========================
   mov esp,ebp
   pop ebp
ret
