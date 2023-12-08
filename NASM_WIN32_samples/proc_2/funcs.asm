global formula
global cube

BITS 32

segment .stack use 32
stack times 1000 db 0

segment .code use32
;����ணࠬ�� ���� ���� c=x^3+y^3
formula:
   ;ebp+8  - [x]
   ;ebp+12 - [y]
   ;ebp+16 - ���� ��� ����� �⢥� result
   ;ebp-4  - h �����쭠� ��६�����
   push dword ebp ;�⠭����� �室 � ����ணࠬ��
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
   mov esp,ebp ;�⠭����� ��室 �� ����ணࠬ��
   pop ebp
ret

;����ணࠬ�� ���� �㡠 �᫠
cube:
   ;ebp+8 - [x]
   push dword ebp ;�⠭����� �室 � ����ணࠬ��
   mov ebp,esp
;---------------
   mov dword ebx,[ebp+8]  ;ebx=[x]
   mov eax,ebx            ;eax=ebx
   xor edx,edx            ;edx=0
   mul dword ebx          ;eax=eax*ebx
   mul dword ebx          ;eax=eax*ebx
;---------------
   mov esp,ebp ;�⠭����� ��室 �� ����ணࠬ��
   pop ebp
;�⢥� ��室���� � eax
ret
