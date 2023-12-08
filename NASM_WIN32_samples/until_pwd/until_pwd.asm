global _main
extern _printf
extern _scanf
extern _strcmp
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
good_name db "boss",0
good_pwd db "bigboss",0
name_ok dd 0
pwd_ok dd 0
log_ok dd 0

name times 100 db 0
pwd times 100 db 0

hello_msg db "�ணࠬ�� �஢�ન ����� � ��஫�",13,10,0

mess_name db "������ ��� ���: ",0
fmt_name db "%s",0

mess_pwd db "������ ��� ��஫�: ",0
fmt_pwd db "%s",0

mess_ok db "���� ����������",13,10,0
mess_error db "�訡��",13,10,0


segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword hello_msg
   call _printf

L1:
;���� �����
   push dword mess_name
   call _printf

   push dword name
   push dword fmt_name
   call _scanf

;���� ��஫�
   push dword mess_pwd
   call _printf

   push dword pwd
   push dword fmt_pwd
   call _scanf
;---------------------------
;�஢�ઠ �����
L_name:
   mov dword [name_ok],0
   push dword name
   push dword good_name
   call _strcmp
   add esp,8
   cmp eax,0
   jne L_pwd
   mov dword [name_ok],1
;�஢�ઠ ��஫�
L_pwd:
   mov dword [pwd_ok],0
   push dword pwd
   push dword good_pwd
   call _strcmp
   add esp,8
   cmp eax,0
   jne L_log
   mov dword [pwd_ok],1
;�믮������ �����᪮� ����樨 log_ok = name_ok AND pwd_ok
L_log:
   mov dword eax,[name_ok]
   mov dword ebx,[pwd_ok]
   and eax,ebx
   mov dword [log_ok],eax
;---------------------------
;�᫨ log_ok=0 � �뢥�� ᮮ�饭�� �� �訡��
   mov dword eax,[log_ok]
   cmp eax,0
   jne L2
   push dword mess_error
   call _printf
   add esp,4
L2:
;---------------------------
   mov dword eax,[log_ok] ;�᫨ ��� ��� ��஫�
   cmp eax,1              ;ᮤ�ঠ�� �訡��, �
   jne near L1           ;�����頥��� � ��砫� 横��
;---------------------------
   push dword mess_ok
   call _printf
;---------------------------
   call _getch ;����প�
;==========================
   mov esp,ebp
   pop ebp
ret
