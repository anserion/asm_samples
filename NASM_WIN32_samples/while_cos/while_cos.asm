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

hello_msg db "�ணࠬ�� �뢮��� ⠡���� ��ᨭ�ᮢ x=a..b � 蠣�� e",13,10,0

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
   finit ;���樠������ ᮯ�����
;---------------------------
;�뢮� ᮮ�饭�� � �����祭�� �ணࠬ��
   push dword hello_msg
   call _printf

;���� a
   push dword mess_a
   call _printf

   push dword af
   push dword fmt_a
   call _scanf
;���४�஢�� af (float->double)
   fld dword [af]
   fst qword [a]
   fwait
;���� b
   push dword mess_b
   call _printf

   push dword bf
   push dword fmt_b
   call _scanf
;���४�஢�� bf (float->double)
   fld dword [bf]
   fst qword [b]
   fwait
;���� e
   push dword mess_e
   call _printf

   push dword ef
   push dword fmt_e
   call _scanf
;���४�஢�� ef (float->double)
   fld dword [ef]
   fst qword [e]
   fwait
;---------------------------
;��騩 ������ �� �몥 C
; x=a;
; while (x<=b) {
;    y=cos(x);
;    printf(tab_str,x,y);
;    x=x+e;
; }
   fld qword [a]    ;x=a
   fst qword [x]
L1:
   finit            ;��। ������ ���樥� ���樠�����㥬 ᮯ�����

   fld qword [x]    ;while (x<=b)
   fcom qword [b]   ;��������� �ࠢ�����
   fstsw ax         ;������ ᫮�� ���ﭨ� ᮯ����� � ॣ���� ax
   fwait
   sahf             ;��७�� ���� ॣ���� ah � eflags
   ja near FINISH   ;�᫮��� ���室 "�᫨ ���" (��-�� ᮯ�����)

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
   add dword esp,20 ;����⠭�������� esp, �.�. printf � 横��

   fld qword [x]    ;x=x+e
   fadd qword [e]
   fst qword [x]
   fwait
;---------------------------
   jmp near L1 ;���室�� � ᫥���饩 ���樨 横��
;---------------------------
FINISH:
   call _getch ;����প�
;==========================
   mov esp,ebp
   pop ebp
ret
