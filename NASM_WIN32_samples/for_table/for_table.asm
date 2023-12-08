global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
N dd 0
i dd 0
j dd 0
p dd 0

hello_msg db "�ணࠬ�� �뢮��� �� �࠭ ⠡���� 㬭������ NxN",13,10,0

mess_N db "N= ",0
fmt_N db "%d",0

fmt_p db "%5d ",0
fmt_enter db 13,10,0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword hello_msg
   call _printf

;���� N
   push dword mess_N
   call _printf

   push dword N
   push dword fmt_N
   call _scanf
;---------------------------
   mov ecx,0 ;����㧪� ॣ���� ���稪� �� ��६����� i
L_i:
   inc ecx           ;㢥��稢��� ���稪 �� 1
   mov dword [i],ecx ;��࠭塞 ���稪 i ��। ���樥� 横��

   mov ecx,0 ;����㧪� ॣ���� ���稪� �� ��६����� j
L_j:
   inc ecx           ;㢥��稢��� ���稪 �� 1
   mov dword [j],ecx ;��࠭塞 ���稪 j ��। ���樥� 横��
;---------------------------
;���� p=i*j
   mov dword eax,[i]
   mov dword ebx,[j]
   mul ebx
   mov dword [p],eax
;�뢮� �祩�� ⠡����
   push dword [p]
   push dword fmt_p
   call _printf
   add esp,8 ;⠪ ��� ������ printf �믮������ � 横��, esp ����⠭��������
;---------------------------
   mov dword ecx,[j] ;����⠭�������� ���稪 j
   cmp ecx,[N]       ;�ࠢ������ ��� � �।���� ���祭���
   jl short L_j      ;� ��砥 ����室����� �����塞 横�
;---------------------------
;��ॢ�� ��ப� ��� ��ᨢ��� ��ଫ���� ⠡����
   push dword fmt_enter
   call _printf
   add esp,4 ;⠪ ��� ������ printf �믮������ � 横��, esp ����⠭��������
;---------------------------
   mov dword ecx,[i] ;����⠭�������� ���稪 i
   cmp ecx,[N]       ;�ࠢ������ ��� � �।���� ���祭���
   jl short L_i      ;� ��砥 ����室����� �����塞 横�
;---------------------------

   call _getch ;����প�
;==========================
   mov esp,ebp
   pop ebp
ret
