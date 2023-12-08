global __Z5func1i ;информация для сборщика
segment .stack use 32
 stack times 1000 db 0

segment .code use 32
__Z5func1i:
   ;ebp+8 - [x]
   push ebp    ;стандартный вход в процедуру
   mov ebp,esp
   ;==========
   mov ebx,[ebp+8] ;загружаем в ebx аргумент
   add ebx,ebx     ;простая арифметическая операция
   mov eax,ebx     ;заносим ответ в регистр eax
   ;==========
   mov esp,ebp ;стандартный выход из процедуры
   pop ebp
   ret ;ответ находится в eax
