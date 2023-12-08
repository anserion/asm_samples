BITS 32

%include "messages.inc"
%include "winstyles.inc"

global _main
extern _printf
extern _scanf
extern _sprintf

extern _MessageBoxA@16
extern _GetModuleHandleA@4
extern _CreateWindowExA@48
extern _LoadIconA@8
extern _LoadCursorA@8
extern _DefWindowProcA@16
extern _PostQuitMessage@4
extern _RegisterClassExA@4
extern _ShowWindow@8
extern _UpdateWindow@4
extern _GetMessageA@16
extern _TranslateMessage@4
extern _DispatchMessageA@4
extern _GetClientRect@8
extern _DrawTextA@20
extern _SendMessageA@16
extern _GetWindowTextA@12
extern _SetWindowTextA@8
extern _GetWindowTextLengthA@4
extern _SetScrollPos@16
extern _SetScrollRange@20


segment .stack use 32
stack times 1000 db 0

segment .data use 32
wc times 12 dd 0
msg times 6 dd 0

winclass db "CLASS32",0
winhwnd dd 0
progtitle db "Win_btns",0

btnclass db "BUTTON",0
scrollclass db "SCROLLBAR",0
;-------------------------------------------------------
btn1_caption db "Quit",0
btn1_hwnd dd 0
btn1_x dd 10
btn1_y dd 10
btn1_dx dd 60
btn1_dy dd 20

chk1_caption db "Check",0
chk1_hwnd dd 0
chk1_x dd 10
chk1_y dd 40
chk1_dx dd 90
chk1_dy dd 20

group1_caption db "Group window",0
group1_hwnd dd 0
group1_x dd 10
group1_y dd 80
group1_dx dd 120
group1_dy dd 90

radio1_caption db "RadioBtn1",0
radio1_hwnd dd 0
radio1_x dd 10
radio1_y dd 180
radio1_dx dd 120
radio1_dy dd 20

radio2_caption db "RadioBtn2",0
radio2_hwnd dd 0
radio2_x dd 10
radio2_y dd 210
radio2_dx dd 120
radio2_dy dd 20

hscroll1_caption db "Horizontal Scroll",0
hscroll1_hwnd dd 0
hscroll1_x dd 10
hscroll1_y dd 300
hscroll1_dx dd 300
hscroll1_dy dd 20
hscroll1_value dd 0
hscroll1_message times 100 db 0

vscroll1_caption db "Vertical Scroll",0
vscroll1_hwnd dd 0
vscroll1_x dd 370
vscroll1_y dd 10
vscroll1_dx dd 20
vscroll1_dy dd 290

;-------------------------------------------------------
edtclass db "EDIT",0
edit1_text db "Programm is running",0
edit1_hwnd dd 0
edit1_x dd 150
edit1_y dd 10
edit1_dx dd 200
edit1_dy dd 100

label1_caption db "Label1",0
label1_hwnd dd 0
label1_x dd 10
label1_y dd 240
label1_dx dd 200
label1_dy dd 20
;-------------------------------------------------------
message_label db "click",0
message_check db "checked",0
message_radio1 db "Radio Button1",0
message_radio2 db "Radio Button2",0
message_vscroll db "Vertical Scroll",0
message_hscroll db "Horizontal Scroll",0

buffer times 100 db 0
fmt_str db "%d",0
;===============================

segment .code use 32
_main:
   push ebp
   mov ebp,esp
;================
regclass:	
	mov dword [wc+WNDCLASSEX.cbSize],48
	mov dword [wc+WNDCLASSEX.style],CS_HREDRAW+CS_VREDRAW+CS_GLOBALCLASS
	mov dword [wc+WNDCLASSEX.lpfnWndProc],winproc
	mov dword [wc+WNDCLASSEX.cbClsExtra],0
        mov dword [wc+WNDCLASSEX.cbWndExtra],0

	call _GetModuleHandleA@4
	mov dword [wc+WNDCLASSEX.hInstance],eax
	
	push dword IDI_APPLICATION
	push dword 0
	call _LoadIconA@8
	mov dword [wc+WNDCLASSEX.hIcon],eax

	push dword IDC_ARROW
	push dword 0
	call _LoadCursorA@8
	mov dword [wc+WNDCLASSEX.hCursor],eax
	
	push dword 0
	mov eax,COLOR_WINDOW
	mov dword [wc+WNDCLASSEX.hbrBackground],eax
	mov dword [wc+WNDCLASSEX.lpszMenuName],0
	mov dword [wc+WNDCLASSEX.lpszClassName],winclass

	push dword IDI_APPLICATION
	push dword 0
	call _LoadIconA@8
	mov dword [wc+WNDCLASSEX.hIconSm],eax

	push dword wc
	call _RegisterClassExA@4

;�������� ���� ��ॣ����஢������ �����
	push dword 0
	push dword [wc+WNDCLASSEX.hInstance]
	push dword 0
	push dword 0
	push dword 400
	push dword 400
	push dword 100
	push dword 100
	push dword WS_OVERLAPPEDWINDOW
	push dword progtitle
	push dword winclass
	push dword 0
	call _CreateWindowExA@48

	cmp eax,0
	je near .exitprog

	mov dword [winhwnd],eax
	push dword SW_SHOWNORMAL
	push dword eax
	call _ShowWindow@8
	push dword [winhwnd]
	call _UpdateWindow@4

;���� ��ࠡ�⪨ ᮮ�饭��
.msgloop:
	push dword 0
	push dword 0
	push dword 0
	push dword msg
	call _GetMessageA@16
	
	cmp eax,0
	je near .exitprog
	
	push dword msg
	call _TranslateMessage@4
	push dword msg
	call _DispatchMessageA@4
	jmp near .msgloop

;��窠 ��室� �� �ணࠬ��
.exitprog:
	push dword .exit_msg
	call _printf
	mov esp,ebp
        pop ebp
        ret
.exit_msg db "��室 �� �ணࠬ��",13,10,0

;===============================
;������� ��楤��
; ebp+20 - lparam
; ebp+16 - wparam
; ebp+12 - msg
; ebp+8  - hwnd
winproc:
	push ebp
	mov ebp,esp
;===============================
	cmp dword [ebp+12], WM_DESTROY
	je near .wmdestroy
	cmp dword [ebp+12], WM_CREATE
	je near .wmcreate
;===============================
	cmp dword [ebp+12], WM_LBUTTONDOWN
	je near .mouse_down

	cmp dword [ebp+12], WM_COMMAND
	je near .wmcommand

	cmp dword [ebp+0ch], WM_VSCROLL
	je near .wmvscroll

	cmp dword [ebp+0ch], WM_HSCROLL
	je near .wmhscroll
;===============================
;��ࠡ��稪� ᮮ�饭��
.default:
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword [ebp+8]
	call _DefWindowProcA@16 ;��ࠡ��稪 ᮮ�饭�� �� 㬮�砭��
	jmp near .finish
;===============================
.mouse_down:
	jmp near .finish

.wmcommand:
;��ࠡ��稪 ������ 1
	mov dword eax,[btn1_hwnd] ;�ࠢ������ ��� ������
	cmp dword [ebp+20],eax    ;� lParam ᮮ�饭��
	je near .wmdestroy        ;�᫨ ᮢ����, � ��室��

;��ࠡ��稪 饫窠 �� ��⪥
.Llabel1:
	mov dword eax,[label1_hwnd] ;�ࠢ������ ��� ��⪨
	cmp dword [ebp+20],eax      ;� lParam ᮮ�饭��
	jne .LEdit1                 ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	push dword message_label
	push dword [label1_hwnd]
	call _SetWindowTextA@8      ;������ ⥪�� �� ��⪥

;��ࠡ��稪 饫窠 �� ���� �����
.LEdit1:
	mov dword eax,[edit1_hwnd] ;�ࠢ������ ��� ���� �����
	cmp dword [ebp+20],eax     ;� lParam ᮮ�饭��
	jne .Lchk1                 ;�᫨ �� ᮢ����, � �ய�᪠�� ���

	push dword -1
	push dword buffer
	push dword [edit1_hwnd]
	call _GetWindowTextA@12   ;����㦠�� � buffer ᮤ�ন��� ���� �����

	push dword buffer
	push dword [label1_hwnd]
	call _SetWindowTextA@8    ;������ ⥪�� �� ��⪥

;��ࠡ��稪 䫠���
.Lchk1:
	mov dword eax,[chk1_hwnd] ;�ࠢ������ ��� 䫠���
	cmp dword [ebp+20],eax    ;� lParam ᮮ�饭��
	jne .Lradio1              ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	push dword message_check
	push dword [edit1_hwnd]
	call _SetWindowTextA@8    ;�뢮��� ᮮ�饭�� � ���� ����� edit1

;��ࠡ��稪 ࠤ�������� 1
.Lradio1:
	mov dword eax,[radio1_hwnd] ;�ࠢ������ ��� ࠤ�������� 1
	cmp dword [ebp+20],eax      ;� lParam ᮮ�饭��
	jne .Lradio2                ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	push dword message_radio1
	push dword [edit1_hwnd]
	call _SetWindowTextA@8      ;�뢮��� ᮮ�饭�� � ���� ����� edit1

;��ࠡ��稪 ࠤ�������� 2
.Lradio2:
	mov dword eax,[radio2_hwnd] ;�ࠢ������ ��� ࠤ�������� 2
	cmp dword [ebp+20],eax      ;� lParam ᮮ�饭��
	jne .Lexit                  ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	push dword message_radio2
	push dword [edit1_hwnd]
	call _SetWindowTextA@8      ;�뢮��� ᮮ�饭�� � ���� ����� edit1

.Lexit:
	jmp near .finish

;===============================
;��ࠡ��稪 ���⨪��쭮� ������� �ப��⪨
;��뢠���� ��� ��� ���⨪����� ������ �ப��⪨ ����
.wmvscroll:
	push dword message_vscroll ;�뢮��� ᮮ�饭�� � ���� ����� edit1
	push dword [edit1_hwnd]    ;� �ந��襤襬 ᮡ�⨨
	call _SetWindowTextA@8     ;"Vertical Scroll"
	jmp near .finish

;��ࠡ��稪 ��ਧ��⠫쭮� ������� �ப��⪨
;[ebp+16] - wParam
.wmhscroll:

.lineup:
	mov dword eax,SB_LINEUP ;�࠭����� ��� ��५�� �����
	cmp word ax,[ebp+16]    ;� LOWORD(wParam) ᮮ�饭��
	jne near .linedown      ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	mov dword eax,[hscroll1_value] ;���� 㬥��蠥� �� 1
	dec eax                        ;���������
	mov dword [hscroll1_value],eax ;����㭪� ������� �ப��⪨

.linedown:	
	mov dword eax,SB_LINEDOWN ;�࠭����� ��� ��५�� ����
	cmp word ax,[ebp+16]      ;� LOWORD(wParam) ᮮ�饭��
	jne near .pageup          ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	mov dword eax,[hscroll1_value] ;���� 㢥��稢��� �� 1
	inc eax                        ;���������
	mov dword [hscroll1_value],eax ;����㭪� ������� �ப��⪨

.pageup:
	mov dword eax,SB_PAGEUP ;�࠭����� ��� ��࠭��� �����
	cmp word ax,[ebp+16]    ;� LOWORD(wParam) ᮮ�饭��
	jne near .pagedown      ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	mov dword eax,[hscroll1_value] ;���� 㬥��蠥� �� 10
	sub eax,10                     ;���������
	mov dword [hscroll1_value],eax ;����㭪� ������� �ப��⪨

.pagedown:
	mov dword eax,SB_PAGEDOWN ;�࠭����� ��� ��࠭��� ����
	cmp word ax,[ebp+16]      ;� LOWORD(wParam) ᮮ�饭��
	jne near .thumbpos        ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	mov dword eax,[hscroll1_value] ;���� 㢥��稢��� �� 10
	add eax,10                     ;���������
	mov dword [hscroll1_value],eax ;����㭪� ������� �ப��⪨

.thumbpos:
	mov dword eax,SB_THUMBPOSITION ;�࠭����� ��� ��筮�� ��६�饭��
	cmp word ax,[ebp+16]           ;� LOWORD(wParam) ᮮ�饭��
	jne near .sethpos              ;�᫨ �� ᮢ����, � �ய�᪠�� ���
	xor eax,eax                    
	mov word ax,[ebp+18]           ;���� ��६ �� HIWORD(wParam)
	mov dword [hscroll1_value],eax ;��������� ����㭪� ������� �ப��⪨

.sethpos:
	push dword 1                   
	push dword [hscroll1_value]
	push dword SB_CTL
	push dword [hscroll1_hwnd]
	call _SetScrollPos@16    ;�ਭ㤨⥫쭠� ��⠭���� ��������� ����㭪�

	push dword [hscroll1_value]
	push dword fmt_str
	push dword hscroll1_message  ;�८�ࠧ㥬 �᫮
	call _sprintf                ;"��������� ����㭪�" � ��ப�
	add esp,12

	push dword hscroll1_message
	push dword [edit1_hwnd]
	call _SetWindowTextA@8      ;�뢮��� ��������� ����㭪� � edit1

	jmp near .finish

;===============================
.wmcreate:
;ᮧ����� ������ 1 (��室)
	push dword btn1_caption
	push dword [btn1_dy]
	push dword [btn1_dx]
	push dword [btn1_y]
	push dword [btn1_x]
	push dword [ebp+8]	
	call MakeButton
	add dword esp,24
	mov dword [btn1_hwnd],eax

;ᮧ����� ��⪨ � ������騬 ⥪�⮬
	push dword label1_caption
	push dword [label1_dy]
	push dword [label1_dx]
	push dword [label1_y]
	push dword [label1_x]
	push dword [ebp+8]	
	call MakeLabel
	add dword esp,24
	mov dword [label1_hwnd],eax

;ᮧ����� ���� �����
	push dword edit1_text
	push dword [edit1_dy]
	push dword [edit1_dx]
	push dword [edit1_y]
	push dword [edit1_x]
	push dword [ebp+8]	
	call MakeEdit
	add esp,24
	mov dword [edit1_hwnd],eax

;ᮧ����� 䫠���
	push dword chk1_caption
	push dword [chk1_dy]
	push dword [chk1_dx]
	push dword [chk1_y]
	push dword [chk1_x]
	push dword [ebp+8]	
	call MakeCheck
	add dword esp,24
	mov dword [chk1_hwnd],eax

;ᮧ����� ���� ��㯯�
	push dword group1_caption
	push dword [group1_dy]
	push dword [group1_dx]
	push dword [group1_y]
	push dword [group1_x]
	push dword [ebp+8]	
	call MakeGroupBox
	add dword esp,24
	mov dword [group1_hwnd],eax

;ᮧ����� ࠤ�������� 1
	push dword radio1_caption
	push dword [radio1_dy]
	push dword [radio1_dx]
	push dword [radio1_y]
	push dword [radio1_x]
	push dword [ebp+8]
	call MakeRadio
	add dword esp,24
	mov dword [radio1_hwnd],eax

;ᮧ����� ࠤ�������� 2
	push dword radio2_caption
	push dword [radio2_dy]
	push dword [radio2_dx]
	push dword [radio2_y]
	push dword [radio2_x]
	push dword [ebp+8]
	call MakeRadio
	add dword esp,24
	mov dword [radio2_hwnd],eax

;ᮧ����� ��ਧ��⠫쭮� ������� �ப��⪨
	push dword hscroll1_caption
	push dword [hscroll1_dy]
	push dword [hscroll1_dx]
	push dword [hscroll1_y]
	push dword [hscroll1_x]
	push dword [ebp+8]	
	call MakeHScroll
	add dword esp,24
	mov dword [hscroll1_hwnd],eax
;��⠭���� �����⨬�� ���祭�� min=0 � max=100
	push dword 0
	push dword 100
	push dword 0
	push dword 2
	push dword [hscroll1_hwnd]
	call _SetScrollRange@20

;ᮧ����� ���⨪��쭮� ������� �ப��⪨
	push dword vscroll1_caption
	push dword [vscroll1_dy]
	push dword [vscroll1_dx]
	push dword [vscroll1_y]
	push dword [vscroll1_x]
	push dword [ebp+8]	
	call MakeVScroll
	add dword esp,24
	mov dword [vscroll1_hwnd],eax
;��⠭���� �����⨬�� ���祭�� min=0 � max=100
	push dword 0
	push dword 100
	push dword 0
	push dword 2
	push dword [vscroll1_hwnd]
	call _SetScrollRange@20

	jmp near .finish

.wmdestroy:
	push dword 0
	call _PostQuitMessage@4
	mov dword eax,0
	jmp near .finish

.finish:
	mov esp,ebp
	pop ebp
	ret

;===============================
;ᮧ����� ������
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeButton:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+BS_DEFPUSHBUTTON+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;ᮧ����� 䫠����
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeCheck:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+BS_AUTOCHECKBOX+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;ᮧ����� ࠤ��������
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeRadio:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+BS_AUTORADIOBUTTON+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;ᮧ����� ���� ��㯯�
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeGroupBox:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+BS_GROUPBOX+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword btnclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;ᮧ����� ��ਧ��⠫쭮� ������� �ப��⪨
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeHScroll:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+SBS_HORZ+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword scrollclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================
;ᮧ����� ���⨪��쭮� ������� �ப��⪨
;ebp+28 - caption
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeVScroll:
	push ebp
	mov ebp,esp
	push 0
	push dword [wc+WNDCLASSEX.hInstance]
	push 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+SBS_VERT+WS_VISIBLE+WS_TABSTOP
	push dword [ebp+28]
	push dword scrollclass
	push 0
	Call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
;===============================

;ᮧ����� ���� �����
;ebp+28 - text
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeEdit:
	push ebp
	mov ebp,esp
	push dword 0
	push dword [wc+WNDCLASSEX.hInstance]
	push dword 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+WS_VISIBLE+WS_BORDER+WS_TABSTOP+ES_MULTILINE+ES_AUTOVSCROLL+WS_VSCROLL
	push dword [ebp+28]
	push dword edtclass
	push 0
	call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret

;ᮧ����� ⥪�⮢�� ��⪨
;ebp+28 - text
;ebp+24 - dy
;ebp+20 - dx
;ebp+16 - y
;ebp+12 - x
;ebp+8 - main_hwnd
MakeLabel:
	push ebp
	mov ebp,esp
	push dword 0
	push dword [wc+WNDCLASSEX.hInstance]
	push dword 0
	push dword [ebp+8]
	push dword [ebp+24]
	push dword [ebp+20]
	push dword [ebp+16]
	push dword [ebp+12]
	push dword WS_CHILD+WS_VISIBLE+ES_MULTILINE+ES_READONLY
	push dword [ebp+28]
	push dword edtclass
	push 0
	call _CreateWindowExA@48
	mov esp,ebp
	pop ebp
	ret
