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

hello_msg db "программа проверки имени и пароля",13,10,0

mess_name db "Введите ваше имя: ",0
fmt_name db "%s",0

mess_pwd db "Введите ваш пароль: ",0
fmt_pwd db "%s",0

mess_ok db "добро пожаловать",13,10,0
mess_error db "ошибка",13,10,0


segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;вывод сообщения о назначении программы
   push dword hello_msg
   call _printf

L1:
;ввод имени
   push dword mess_name
   call _printf

   push dword name
   push dword fmt_name
   call _scanf

;ввод пароля
   push dword mess_pwd
   call _printf

   push dword pwd
   push dword fmt_pwd
   call _scanf
;---------------------------
;проверка имени
L_name:
   mov dword [name_ok],0
   push dword name
   push dword good_name
   call _strcmp
   add esp,8
   cmp eax,0
   jne L_pwd
   mov dword [name_ok],1
;проверка пароля
L_pwd:
   mov dword [pwd_ok],0
   push dword pwd
   push dword good_pwd
   call _strcmp
   add esp,8
   cmp eax,0
   jne L_log
   mov dword [pwd_ok],1
;выполнение логической операции log_ok = name_ok AND pwd_ok
L_log:
   mov dword eax,[name_ok]
   mov dword ebx,[pwd_ok]
   and eax,ebx
   mov dword [log_ok],eax
;---------------------------
;если log_ok=0 то вывести сообщение об ошибке
   mov dword eax,[log_ok]
   cmp eax,0
   jne L2
   push dword mess_error
   call _printf
   add esp,4
L2:
;---------------------------
   mov dword eax,[log_ok] ;если имя или пароль
   cmp eax,1              ;содержали ошибку, то
   jne near L1           ;возвращаемся к началу цикла
;---------------------------
   push dword mess_ok
   call _printf
;---------------------------
   call _getch ;задержка
;==========================
   mov esp,ebp
   pop ebp
ret
