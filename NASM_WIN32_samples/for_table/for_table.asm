global _main
extern _printf
extern _scanf
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
N dd 0
i dd 0
j dd 0
p dd 0

hello_msg db "программа выводит на экран таблицу умножения NxN",13,10,0

mess_N db "N= ",0
fmt_N db "%d",0

fmt_p db "%5d ",0
fmt_enter db 13,10,0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;вывод сообщения о назначении программы
   push dword hello_msg
   call _printf

;ввод N
   push dword mess_N
   call _printf

   push dword N
   push dword fmt_N
   call _scanf
;---------------------------
   mov ecx,0 ;загрузка регистра счетчика по переменной i
L_i:
   inc ecx           ;увеличиваем счетчик на 1
   mov dword [i],ecx ;сохраняем счетчик i перед итерацией цикла

   mov ecx,0 ;загрузка регистра счетчика по переменной j
L_j:
   inc ecx           ;увеличиваем счетчик на 1
   mov dword [j],ecx ;сохраняем счетчик j перед итерацией цикла
;---------------------------
;расчет p=i*j
   mov dword eax,[i]
   mov dword ebx,[j]
   mul ebx
   mov dword [p],eax
;вывод ячейки таблицы
   push dword [p]
   push dword fmt_p
   call _printf
   add esp,8 ;так как оператор printf выполняется в цикле, esp восстанавливаем
;---------------------------
   mov dword ecx,[j] ;восстанавливаем счетчик j
   cmp ecx,[N]       ;сравниваем его с предельным значением
   jl short L_j      ;в случае необходимости повторяем цикл
;---------------------------
;перевод строки для красивого оформления таблицы
   push dword fmt_enter
   call _printf
   add esp,4 ;так как оператор printf выполняется в цикле, esp восстанавливаем
;---------------------------
   mov dword ecx,[i] ;восстанавливаем счетчик i
   cmp ecx,[N]       ;сравниваем его с предельным значением
   jl short L_i      ;в случае необходимости повторяем цикл
;---------------------------

   call _getch ;задержка
;==========================
   mov esp,ebp
   pop ebp
ret
