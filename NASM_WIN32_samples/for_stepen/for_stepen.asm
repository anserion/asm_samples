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

hello_msg db "программа вычисляет значение a^n",13,10,0

mess_a db "a= ",0
fmt_a db "%d",0

mess_n db "n= ",0
fmt_n db "%d",0

otvet db "Ответ: a^n=%d",13,10,0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;вывод сообщения о назначении программы
   push dword hello_msg
   call _printf

;ввод a
   push dword mess_a
   call _printf

   push dword a
   push dword fmt_a
   call _scanf
;---------------------------
;ввод n
   push dword mess_n
   call _printf

   push dword n
   push dword fmt_n
   call _scanf
;---------------------------
   mov dword ecx,[n] ;загрузка регистра счетчика
L1:
   mov dword [i],ecx ;сохраняем счетчик перед итерацией цикла

   mov dword eax,[p] ;жутко неэффективный
   mov dword ebx,[a] ;код, демонстрирующий
   mul ebx           ;выполнение операции
   mov dword [p],eax ;p=p*a

   mov dword ecx,[i] ;восстанавливаем счетчик
   loop L1  ;циклический оператор (уменьшает счетчик!)
;---------------------------
;вывод ответа
   push dword [p]
   push dword otvet
   call _printf
;---------------------------
   call _getch ;задержка
;==========================
   mov esp,ebp
   pop ebp
ret
