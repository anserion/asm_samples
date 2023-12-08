global _main
extern _printf
extern _scanf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0 ;память для переменной a
b dd 0 ;память для переменной b
c dd 0 ;память для переменной c
r dd 0 ;память для переменной r

mess_a db "a= ",0 ;текст сообщения для ввода значения a
fmt_a db "%d",0   ;a - целое число

mess_b db "b= ",0 ;текст сообщения для ввода значения b
fmt_b db "%d",0   ;b - целое число

otv1 db "Ответ: a+b= %d",13,10,0
otv2 db "Ответ: a-b= %d",13,10,0
otv3 db "Ответ: a*b= %d",13,10,0
otv4 db "Ответ: a/b= %d (остаток %d)",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
;вывод сообщения "a="
   push dword mess_a
   call _printf
   add dword esp,4
;ввод значения переменной a
   push dword a
   push dword fmt_a
   call _scanf
   add dword esp,8
;---------------------------
;вывод сообщения "b="
   push dword mess_b
   call _printf
   add dword esp,4
;ввод значения переменной b
   push dword b
   push dword fmt_b
   call _scanf
   add dword esp,8
;---------------------------
;сложение
   mov dword eax,[a]
   add dword eax,[b]
   mov dword [c],eax
;---------------------------
;вывод ответа сложения
   push dword [c]
   push dword otv1
   call _printf
   add dword esp,8
;---------------------------
;вычитание
   mov dword eax,[a]
   sub dword eax,[b]
   mov dword [c],eax
;---------------------------
;вывод ответа вычитания
   push dword [c]
   push dword otv2
   call _printf
   add dword esp,8
;---------------------------
;умножение
   mov dword eax,[a]
   mov dword edx,0
   mul dword [b]
   mov dword [c],eax
;---------------------------
;вывод ответа умножения
   push dword [c]
   push dword otv3
   call _printf
   add dword esp,8
;---------------------------
;деление
   mov dword eax,[a]
   mov dword edx,0
   div dword [b]
   mov dword [c],eax
   mov dword [r],edx
;---------------------------
;вывод ответа деления
   push dword [r]
   push dword [c]
   push dword otv4
   call _printf
   add dword esp,12
;==========================
   mov esp,ebp
   pop ebp
ret
