global _main
extern _printf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 15
b dd 13
c resd 1
mess_a db "a= %d",13,10,0
mess_b db "b= %d",13,10,0
mess_otv db "Ответ: %d",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
   push dword [a]
   push dword mess_a
   call _printf
   add dword esp,8

   push dword [b]
   push dword mess_b
   call _printf
   add dword esp,8
;---------------------------
   mov dword eax,[a]
   add dword eax,[b]
   mov dword [c],eax
;---------------------------
   push dword [c]
   push dword mess_otv
   call _printf
   add dword esp,8
;==========================
   mov esp,ebp
   pop ebp
ret
