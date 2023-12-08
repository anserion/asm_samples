global formula
global cube

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .code use32
;подпрограмма расчета формулы c=x^3+y^3
formula:
   ;ebp+8  - [x]
   ;ebp+12 - [y]
   ;ebp+16 - адрес для записи ответа result
   ;ebp-4  - h локальная переменная
   push dword ebp ;стандартный вход в подпрограмму
   mov ebp,esp
;---------------
   push dword [ebp+8]
   call cube
   mov dword [ebp-4],eax ;h=x^3

   push dword [ebp+12]
   call cube
   add dword eax,[ebp-4] ;eax=h+y^3

   mov dword ebx,[ebp+16]
   mov dword [ebx],eax    ; *result=eax
;---------------
   mov esp,ebp ;стандартный выход из подпрограммы
   pop ebp
ret

;подпрограмма расчета куба числа
cube:
   ;ebp+8 - [x]
   push dword ebp ;стандартный вход в подпрограмму
   mov ebp,esp
;---------------
   mov dword ebx,[ebp+8]  ;ebx=[x]
   mov eax,ebx            ;eax=ebx
   xor edx,edx            ;edx=0
   mul dword ebx          ;eax=eax*ebx
   mul dword ebx          ;eax=eax*ebx
;---------------
   mov esp,ebp ;стандартный выход из подпрограммы
   pop ebp
;ответ находится в eax
ret
