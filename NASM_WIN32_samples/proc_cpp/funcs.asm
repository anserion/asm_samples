global __Z5func1i ;���������� ��� ��������
segment .stack use 32
 stack times 1000 db 0

segment .code use 32
__Z5func1i:
   ;ebp+8 - [x]
   push ebp    ;����������� ���� � ���������
   mov ebp,esp
   ;==========
   mov ebx,[ebp+8] ;��������� � ebx ��������
   add ebx,ebx     ;������� �������������� ��������
   mov eax,ebx     ;������� ����� � ������� eax
   ;==========
   mov esp,ebp ;����������� ����� �� ���������
   pop ebp
   ret ;����� ��������� � eax
