global _main
extern _printf
extern _scanf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
mess1 db "Введите ваше имя: ",0
fmt_name db "%s",0
str_name resb 100
mess2 db "Привет, %s",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
   push dword mess1
   call _printf
   add dword esp,4

   push dword str_name
   push dword fmt_name
   call _scanf
   add dword esp,8

   push dword str_name
   push dword mess2
   call _printf
   add dword esp,8
;==========================
   mov esp,ebp
   pop ebp
ret
