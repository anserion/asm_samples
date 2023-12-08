global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
a dd 0
b dd 0

hello_msg db "программа сравнения двух чисел a и b",13,10,0

mess_a db "a= ",0
fmt_a db "%d",0

mess_b db "b= ",0
fmt_b db "%d",0

otv1 db "Ответ: a>b",13,10,0
otv2 db "Ответ: a<b",13,10,0
otv3 db "Ответ: a=b",13,10,0

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
;ввод b
   push dword mess_b
   call _printf

   push dword b
   push dword fmt_b
   call _scanf
;---------------------------
;сравнение (a и b)
   mov dword eax,[a]
   mov dword ebx,[b]
   cmp eax,ebx
;---------------------------
   jg short L1 ;если a>b
   jl short L2 ;если a<b
;---------------------------
;если a=b
   push dword otv3
   call _printf
   jmp short FINISH
;---------------------------
;если a>b
L1:
   push dword otv1
   call _printf
   jmp short FINISH
;---------------------------
;если a<b
L2:
   push dword otv2
   call _printf
;---------------------------
FINISH:
   call _getch ;задержка
;==========================
   mov esp,ebp
   pop ebp
ret
