global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
a dd 0

hello_msg db "�ணࠬ�� �뢮��� ᫮��᭮� �������� ����",13,10,0

mess_a db "a= ",0
fmt_a db "%d",0

otv0 db "�⢥�: ���",13,10,0
otv1 db "�⢥�: ����",13,10,0
otv2 db "�⢥�: ���",13,10,0
otv3 db "�⢥�: ��",13,10,0
otv4 db "�⢥�: ����",13,10,0
otv5 db "�⢥�: ����",13,10,0
otv6 db "�⢥�: ����",13,10,0
otv7 db "�⢥�: ᥬ�",13,10,0
otv8 db "�⢥�: ��ᥬ�",13,10,0
otv9 db "�⢥�: ������",13,10,0
otv_def db "�⢥�: ��� �� ��।�����",13,10,0

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
   mov dword eax,[a]
;�ࠢ����� eax � �᫠�� 0..9
   cmp eax,0
   je short L0

   cmp eax,1
   je short L1

   cmp eax,2
   je short L2

   cmp eax,3
   je short L3

   cmp eax,4
   je short L4

   cmp eax,5
   je short L5

   cmp eax,6
   je short L6

   cmp eax,7
   je short L7

   cmp eax,8
   je short L8

   cmp eax,9
   je short L9
;��⪠ ���� (default)
   push dword otv_def
   call _printf
   jmp short FINISH
;---------------------------
L0:
   push dword otv0
   call _printf
   jmp short FINISH
L1:
   push dword otv1
   call _printf
   jmp short FINISH
L2:
   push dword otv2
   call _printf
   jmp short FINISH
L3:
   push dword otv3
   call _printf
   jmp short FINISH
L4:
   push dword otv4
   call _printf
   jmp short FINISH
L5:
   push dword otv5
   call _printf
   jmp short FINISH
L6:
   push dword otv6
   call _printf
   jmp short FINISH
L7:
   push dword otv7
   call _printf
   jmp short FINISH
L8:
   push dword otv8
   call _printf
   jmp short FINISH
L9:
   push dword otv9
   call _printf
   jmp short FINISH
;---------------------------
FINISH:
   call _getch ;����প�
;==========================
   mov esp,ebp
   pop ebp
ret
