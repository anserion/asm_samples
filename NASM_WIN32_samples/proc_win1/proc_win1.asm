global _main

extern _printf
extern _sprintf
extern _scanf
extern _MessageBoxA@16

bits 32

segment .stack use 32
stack times 1000 db 0

segment .data use 32
btn_caption db "Hello",0
btn_fmt db "Hello, %s",0
question1 db "Введите ваше имя:",0
str_fmt db "%s",0
name_str resb 100
btn_str resb 100

segment .code use 32
_main:
   push ebp
   mov ebp,esp
   ;==================
;выводим на экран запрос на ввод имени
   push dword question1
   call _printf
   add esp,4
;считываем имя с клавиатуры
   push dword name_str
   push dword str_fmt
   call _scanf
   add esp,8
;складываем две строки в одну
   push dword name_str
   push dword btn_fmt
   push dword btn_str
   call _sprintf
   add esp,12
;выводим на экран диалоговое окно с приветствием
   call hello_box
   ;==================
   mov esp,ebp
   pop ebp
   ret

;подпрограмма вывода диалогового окна
hello_box:
   push dword 0 ;MB_OK
   push dword btn_caption
   push dword btn_str
   push dword 0 ;parent HWND
   call _MessageBoxA@16
ret
