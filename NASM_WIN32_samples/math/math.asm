global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .data use32
aa dd 0.0 ;память для вещественной переменной a типа float
bb dd 0.0 ;память для вещественной переменной b типа float

a dq 0.0 ;память для вещественной переменной a типа double
b dq 0.0 ;память для вещественной переменной b типа double
c dq 0.0 ;память для вещественной переменной c типа double

x dd 0; память для целой переменной x

mess_a db "a= ",0 ;текст сообщения для ввода значения a
mess_b db "b= ",0 ;текст сообщения для ввода значения b
fmt_str db "%f",0 ;вещественное число float

otv_sum db "Ответ: a+b= %f",13,10,0
otv_vic db "Ответ: a-b= %f",13,10,0
otv_umn db "Ответ: a*b= %f",13,10,0
otv_del db "Ответ: a/b= %f",13,10,0
otv_neg db "Ответ: -a= %f",13,10,0
otv_sqrt db "Ответ: sqrt(a)= %f",13,10,0
otv_abs db "Ответ: abs(a)= %f",13,10,0
otv_sin db "Ответ: sin(a)= %f",13,10,0
otv_cos db "Ответ: cos(a)= %f",13,10,0
otv_atan db "Ответ: arctg(a/b)= %f",13,10,0
otv_log2 db "Ответ: log2(a)= %f",13,10,0
otv_cel db "Ответ: a(double)->x(int)=%d",13,10,0
otv_dbl db "Ответ: x+1(int)->c(double)=%f",13,10,0

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
   push dword aa
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;вывод сообщения "b="
   push dword mess_b
   call _printf
   add dword esp,4
;ввод значения переменной b
   push dword bb
   push dword fmt_str
   call _scanf
   add dword esp,8
;---------------------------
;инициализация сопроцессора
   finit
;---------------------------
;перевод введенных значений a и b из float в double
   fld dword [aa]
   fst qword [a]

   fld dword [bb]
   fst qword [b]
;---------------------------
;сложение на сопроцессоре
   fld qword [a]
   fadd qword [b]
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_sum
   call _printf
   add dword esp,12
;---------------------------
;вычитание на сопроцессоре
   fld qword [a]
   fsub qword [b]
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_vic
   call _printf
   add dword esp,12
;---------------------------
;умножение на сопроцессоре
   fld qword [a]
   fmul qword [b]
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_umn
   call _printf
   add dword esp,12
;---------------------------
;деление на сопроцессоре
   fld qword [a]
   fdiv qword [b]
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_del
   call _printf
   add dword esp,12
;---------------------------
;изменение знака на сопроцессоре
   fld qword [a]
   fchs
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_neg
   call _printf
   add dword esp,12
;---------------------------
;вычисление корня квадратного на сопроцессоре
   fld qword [a]
   fsqrt
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_sqrt
   call _printf
   add dword esp,12
;---------------------------
;нахождение модуля (абсолютного значения) на сопроцессоре
   finit
   fld qword [a]
   fabs
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_abs
   call _printf
   add dword esp,12
;---------------------------
;вычисление синуса на сопроцессоре
   fld qword [a]
   fsin
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_sin
   call _printf
   add dword esp,12
;---------------------------
;вычисление косинуса на сопроцессоре
   fld qword [a]
   fcos
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_cos
   call _printf
   add dword esp,12
;---------------------------
;вычисление арктангенса на сопроцессоре
   fld qword [a]
   fst st1
   fld qword [b]
   fpatan
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_atan
   call _printf
   add dword esp,12
;---------------------------
;вычисление логарифма по основанию 2 на сопроцессоре
   fld1
   fst st1
   fld qword [a]
   fyl2x
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_log2
   call _printf
   add dword esp,12
;---------------------------
;преобразование из вещественного в целое на сопроцессоре
   fld qword [a]
   fist dword [x]
   fwait
;вывод ответа
   push dword [x]
   push dword otv_cel
   call _printf
   add dword esp,12
;---------------------------
;преобразование из целого в вещественное на сопроцессоре
;-----------
   mov dword eax,[x] ;простое увеличение
   add eax,1         ;содержимого [x] на 1
   mov dword [x],eax
;-----------
   fild dword [x]
   fst qword [c]
   fwait
;вывод ответа
   push dword [c+4]
   push dword [c]
   push dword otv_dbl
   call _printf
   add dword esp,12

;==========================
   mov esp,ebp
   pop ebp
ret
