global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
a dq 0.0
b dq 0.0
x dq 0.0
y dq 0.0
e dq 1.0

af dd 0
bf dd 0
ef dd 0

hello_msg db "программа выводит таблицу косинусов x=a..b с шагом e",13,10,0

mess_a db "a= ",0
fmt_a db "%f",0

mess_b db "b= ",0
fmt_b db "%f",0

mess_e db "e= ",0
fmt_e db "%f",0

tab_str db "x=%f, cos(x)=%f",13,10,0

flag_str db "flag=%d",13,10,0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
   finit ;инициализация сопроцессора
;---------------------------
;вывод сообщения о назначении программы
   push dword hello_msg
   call _printf

;ввод a
   push dword mess_a
   call _printf

   push dword af
   push dword fmt_a
   call _scanf
;корректировка af (float->double)
   fld dword [af]
   fst qword [a]
   fwait
;ввод b
   push dword mess_b
   call _printf

   push dword bf
   push dword fmt_b
   call _scanf
;корректировка bf (float->double)
   fld dword [bf]
   fst qword [b]
   fwait
;ввод e
   push dword mess_e
   call _printf

   push dword ef
   push dword fmt_e
   call _scanf
;корректировка ef (float->double)
   fld dword [ef]
   fst qword [e]
   fwait
;---------------------------
;общий алгоритм на языке C
; x=a;
; while (x<=b) {
;    y=cos(x);
;    printf(tab_str,x,y);
;    x=x+e;
; }
   fld qword [a]    ;x=a
   fst qword [x]
L1:
   finit            ;перед каждой итерацией инициализируем сопроцессор

   fld qword [x]    ;while (x<=b)
   fcom qword [b]   ;мнемоника сравнения
   fstsw ax         ;запись слова состояния сопроцессора в регистр ax
   fwait
   sahf             ;перенос биотв регистра ah в eflags
   ja near FINISH   ;условный переход "если выше" (из-за сопроцессора)

   fld qword [x]    ;y=cos(x)
   fcos
   fst qword [y]
   fwait

   push dword [y+4] ;printf(tab_str,x,y)
   push dword [y]
   push dword [x+4]
   push dword [x]
   push dword tab_str
   call _printf
   add dword esp,20 ;восстанавливаем esp, т.к. printf в цикле

   fld qword [x]    ;x=x+e
   fadd qword [e]
   fst qword [x]
   fwait
;---------------------------
   jmp near L1 ;переходим к следующей итерации цикла
;---------------------------
FINISH:
   call _getch ;задержка
;==========================
   mov esp,ebp
   pop ebp
ret
