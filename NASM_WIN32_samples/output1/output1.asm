global _main
extern _printf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
message db "Привет, мир!",13,10,0
mess1 db "Паро",0
mess2 db "воз",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
   push dword message
   call _printf
   add dword esp,4

   push dword mess1
   call _printf
   add dword esp,4

   push dword mess2
   call _printf
   add dword esp,4
;==========================
   mov esp,ebp
   pop ebp
ret
