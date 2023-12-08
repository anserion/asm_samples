global _main
extern _printf
extern _scanf
extern _getch

extern formula
extern cube

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
a dd 0 ;память для переменной a
b dd 0 ;память для переменной b
c dd 0 ;память для переменной c
mess_a db "a= ",0 ;текст сообщения для ввода значения a
mess_b db "b= ",0 ;текст сообщения для ввода значения b
fmt_dec db "%d",0  ;целое число

otv1 db "Ответ: a^3+b^3= %d",13,10,0

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
   push dword fmt_dec
   call _scanf
   add dword esp,8

;вывод сообщения "b="
   push dword mess_b
   call _printf
   add dword esp,4
;ввод значения переменной b
   push dword b
   push dword fmt_dec
   call _scanf
   add dword esp,8
;расчет формулы c=a^3+b^3
   push dword c
   push dword [b]
   push dword [a]
   call formula
   add esp,12
;вывод ответа 
   push dword [c]
   push dword otv1
   call _printf
   add esp,8
;задержка перед выходом
  call _getch
;==========================
   mov esp,ebp
   pop ebp
ret
