global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use 32
;--------------------------------
;Объявляем структуру complex
;--------------------------------
struc complex
.re resd 1
.im resd 1
endstruc
;--------------------------------

;--------------------------------
;инициализируем переменные a,b,c
;экземпляры структуры complex
;--------------------------------
a istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend

b istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend

c istruc complex
at complex.re, dd 0
at complex.im, dd 0
iend
;--------------------------------

intro_msg db "программа сложения и вычитания комплексных чисел",13,10,0
exit_msg db "нажмите любую кнопку на клавиатуре для выхода",13,10,0

mess_a_re db "a.re= ",0 ;текст сообщения для ввода значения a
mess_a_im db "a.im= ",0 ;текст сообщения для ввода значения a

mess_b_re db "b.re= ",0 ;текст сообщения для ввода значения b
mess_b_im db "b.im= ",0 ;текст сообщения для ввода значения b

fmt_str db "%d",0 ;форматирующая строка для целого числа


otv1 db "Ответ: a+b= %d + i* %d",13,10,0
otv2 db "Ответ: a-b= %d + i* %d",13,10,0

segment .code use32
_main:
   push ebp
   mov ebp,esp
;===========================
;вывод сообщения о назначении программы
   push dword intro_msg
   call _printf
   add dword esp,4
;вывод сообщения "a.re="
   push dword mess_a_re
   call _printf
   add dword esp,4
;ввод значения переменной a.re
   push dword a+complex.re
   push dword fmt_str
   call _scanf
   add dword esp,8
;вывод сообщения "a.im="
   push dword mess_a_im
   call _printf
   add dword esp,4
;ввод значения переменной a.im
   push dword a+complex.im
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;вывод сообщения "b.re="
   push dword mess_b_re
   call _printf
   add dword esp,4
;ввод значения переменной b.re
   push dword b+complex.re
   push dword fmt_str
   call _scanf
   add dword esp,8
;вывод сообщения "b.im="
   push dword mess_b_im
   call _printf
   add dword esp,4
;ввод значения переменной b.im
   push dword b+complex.im
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;сложение комплексных чисел
   mov dword eax,[a+complex.re]
   add dword eax,[b+complex.re]
   mov dword [c+complex.re],eax

   mov dword eax,[a+complex.im]
   add dword eax,[b+complex.im]
   mov dword [c+complex.im],eax
;---------------------------
;вывод ответа сложения комплексных чисел
   push dword [c+complex.im]
   push dword [c+complex.re]
   push dword otv1
   call _printf
   add dword esp,12
;---------------------------
;вычитание комплексных чисел
   mov dword eax,[a+complex.re]
   sub dword eax,[b+complex.re]
   mov dword [c+complex.re],eax

   mov dword eax,[a+complex.im]
   sub dword eax,[b+complex.im]
   mov dword [c+complex.im],eax
;---------------------------
;вывод ответа вычитания комплексных чисел
   push dword [c+complex.im]
   push dword [c+complex.re]
   push dword otv2
   call _printf
   add dword esp,8
;----------------------------
;задержка вывода до нажатия любой клавиши
   push dword exit_msg
   call _printf
   add dword esp,4
   call _getch
;==========================
   mov esp,ebp
   pop ebp
ret
