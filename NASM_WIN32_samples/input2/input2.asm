global _main
extern _printf
extern _scanf

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0
b dd 0
c dd 0

mess_a db "a= ",0
fmt_a db "%d",0

mess_b db "b= ",0
fmt_b db "%d",0

mess_otv db "Ответ: %d",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
   push dword mess_a
   call _printf
   add dword esp,4

   push dword a
   push dword fmt_a
   call _scanf
   add dword esp,8
;---------------------------
   push dword mess_b
   call _printf
   add dword esp,4

   push dword b
   push dword fmt_b
   call _scanf
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
