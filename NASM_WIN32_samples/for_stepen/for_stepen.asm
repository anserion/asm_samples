global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
a dd 0
n dd 0
i dd 0
p dd 1

hello_msg db "�ணࠬ�� ������ ���祭�� a^n",13,10,0

mess_a db "a= ",0
fmt_a db "%d",0

mess_n db "n= ",0
fmt_n db "%d",0

otvet db "�⢥�: a^n=%d",13,10,0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword hello_msg
   call _printf

;���� a
   push dword mess_a
   call _printf

   push dword a
   push dword fmt_a
   call _scanf
;---------------------------
;���� n
   push dword mess_n
   call _printf

   push dword n
   push dword fmt_n
   call _scanf
;---------------------------
   mov dword ecx,[n] ;����㧪� ॣ���� ���稪�
L1:
   mov dword [i],ecx ;��࠭塞 ���稪 ��। ���樥� 横��

   mov dword eax,[p] ;��⪮ ����䥪⨢��
   mov dword ebx,[a] ;���, �����������騩
   mul ebx           ;�믮������ ����樨
   mov dword [p],eax ;p=p*a

   mov dword ecx,[i] ;����⠭�������� ���稪
   loop L1  ;横���᪨� ������ (㬥��蠥� ���稪!)
;---------------------------
;�뢮� �⢥�
   push dword [p]
   push dword otvet
   call _printf
;---------------------------
   call _getch ;����প�
;==========================
   mov esp,ebp
   pop ebp
ret
