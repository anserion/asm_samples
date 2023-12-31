global _main
extern _printf
extern _scanf
extern _malloc
extern _free
extern _getch

BITS 32

segment .stack
stack times 1000 db 0

segment .data
N dd 0
A dd 0

hello_msg db "�ணࠬ�� ����� ���ᨢ� A[] � ���������� � �뢮�� ��� �� ��࠭",13,10,0

mess_N db "N= ",0
fmt_N db "%d",0

segment .code
_main:
   push ebp
   mov ebp,esp
;===========================
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword hello_msg
   call _printf

;���� N
   push dword mess_N
   call _printf

   push dword N
   push dword fmt_N
   call _scanf
;---------------------------
;������ ࠧ��� �����, ����室���� ��� �࠭���� ���ᨢ� eax=[N]*4+4
   mov dword eax,[N] ;�����뢠�� ��ꥬ �����,
   mov dword ebx,4   ;����室���� ��� �࠭���� N
   mul ebx           ;4-���⮢�� �ᥫ
   add eax,4         ;������ 4 ���� �.�. ����� �����ᮢ �㤥� � 1, � �� � 0
;---------------------------
;ᮡ�⢥��� �뤥����� ����� ��� ���ᨢ� [A]=malloc(eax)
   push dword eax ;����㦠�� � �⥪ ࠧ��� �ॡ㥬�� �����
   call _malloc    ;��뢠�� �㭪�� �������᪮�� �뤥����� �����
   add esp,4      ;����⠭�������� �⥪
   mov dword [A],eax ;��࠭塞 ���� ��砫� �뤥������� ����� ����� � [A]
;---------------------------
;���� ���ᨢ� � ���������� input_array(N,A)
   push dword [A] ;����㦠�� ���� ��砫� ���ᨢ�
   push dword [N] ;����㦠�� �᫮ ������⮢ ���ᨢ�
   call input_array ;������ ���ᨢ � ����������
   add esp,8      ;����⠭�������� �⥪
;---------------------------
;�뢮� ���ᨢ� �� ��࠭ print_array(N,A)
   push dword [A] ;����㦠�� ���� ��砫� ���ᨢ�
   push dword [N] ;����㦠�� �᫮ ������⮢ ���ᨢ�
   call print_array ;�뢮��� ���ᨢ �� ��࠭
   add esp,8      ;����⠭�������� �⥪
;---------------------------
;�⤠�� �뤥������ �������᪨ ������ free(A)
   push dword [A] ;����㦠�� ���� ��砫� �����-� �뤥������ �����
   call _free      ;��뢠�� �㭪�� ��᢮�������� �����
   add esp,4      ;����⠭�������� �⥪
;---------------------------   
   call _getch ;����প�
;---------------------------   
   mov esp,ebp
   pop ebp
ret


;---------------------------
;�뢮� ������⮢ ���ᨢ� �� ��࠭
;---------------------------
;ebp+8 --- N �᫮ ������⮢ ���ᨢ�
;ebp+12  --- A 㪠��⥫� �� ��砫� ���ᨢ�
;ebp-4  --- �����쭠� ��६����� i
;---------------------------
print_array:
   push ebp
   mov ebp,esp
   sub esp,4
;---------------------------
   mov ecx,0 ;����㧪� ॣ���� ���稪� �� ��६����� i
.L_i:
   inc ecx           ;㢥��稢��� ���稪 �� 1
   mov dword [ebp-4],ecx ;��࠭塞 ���稪 i ��। ���樥� 横��
;---------------------------
   mov dword ebx,[ebp+12] ;����㦠�� � ॣ���� ���� ���� ��砫� ���ᨢ�
   mov dword edi,[ebp-4] ;����㦠�� � ������� ॣ���� ����� �������
;�뢮��� i-� ������� ���ᨢ� A �� ��࠭
   push dword [ebx+edi*4] ;��堭��� ᬥ蠭��� ����樨
   push dword [ebp-4]
   push dword .elem_A
   call _printf
   add esp,8 ;⠪ ��� ������ printf �믮������ � 横��, esp ����⠭��������
;---------------------------
   mov dword ecx,[ebp-4] ;����⠭�������� ���稪 i
   cmp ecx,[ebp+8]  ;�ࠢ������ ��� � �।���� ���祭���
   jl short .L_i     ;� ��砥 ����室����� �����塞 横�

;�⠭����� ��室 �� ����ணࠬ��
   mov esp,ebp
   pop ebp
ret
.elem_A db "A[%d]=%4d  ",0 ;�ଠ������ ��ப� �뢮�� ������� ���ᨢ�
;ࠧ��饭�� .elem_A � ᥣ���� ���� ����� ������ ����� (���宩 �⨫�)
;�� �� �ਢ���� � �⠫�� ��᫥��⢨�, �.�. �ᯮ������ ⮫쪮 ��� �⥭��


;---------------------------
;���� ������⮢ ���ᨢ� � ����������
;---------------------------
;ebp+8  --- N �᫮ ������⮢ ���ᨢ�
;ebp+12 --- A 㪠��⥫� �� ��砫� ���ᨢ�
;ebp-4  --- �����쭠� ��६����� i
;---------------------------
input_array:
   push ebp
   mov ebp,esp
   sub esp,4
;---------------------------
   mov ecx,0 ;����㧪� ॣ���� ���稪� �� ��६����� i
.L_i:
   inc ecx           ;㢥��稢��� ���稪 �� 1
   mov dword [ebp-4],ecx ;��࠭塞 ���稪 i ��। ���樥� 横��

;�뢮��� �ਣ��襭�� � ����� A[i]
   push dword ecx
   push dword .mess_A 
   call _printf
   add esp,8 ;⠪ ��� ������ printf �믮������ � 横��, esp ����⠭��������

;�����뢠�� ᬥ饭�� �� ��砫� ���ᨢ� �� ��㫥 eax=4*[i]+[A]
   mov dword ebx,[ebp+12] ;����㦠�� � ॣ���� ���� ���� ��砫� ���ᨢ�
   mov dword edi,[ebp-4] ;����㦠�� � ������� ॣ���� ����� �������
   lea dword eax,[ebx+edi*4] ;����㦠�� � eax ���� i-�� ������� ���ᨢ�
;ᮡ�⢥��� ���� ������� ���ᨢ�
   push dword eax
   push dword .fmt_A
   call _scanf
   add esp,8 ;⠪ ��� ������ scanf �믮������ � 横��, esp ����⠭��������
;---------------------------
   mov dword ecx,[ebp-4] ;����⠭�������� ���稪 i
   cmp ecx,[ebp+8]       ;�ࠢ������ ��� � �।���� ���祭���
   jl short .L_i     ;� ��砥 ����室����� �����塞 横�
;---------------------------
;�⠭����� ��室 �� ����ணࠬ��
   mov esp,ebp
   pop ebp
ret
.mess_A db "A[%d]= ",0
.fmt_A db "%d",0
;ࠧ��饭�� .mess_A � .fmt_A � ᥣ���� ���� ����� ������ ����� (���宩 �⨫�)
;�� �� �ਢ���� � �⠫�� ��᫥��⢨�, �.�. �ᯮ������ ⮫쪮 ��� �⥭��
;---------------------------
