
;===============================
;создание кнопки
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
;создание флажков
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
;создание радиокнопки
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
;создание окна группы
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
;создание горизонтальной линейки прокрутки
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
;создание вертикальной линейки прокрутки
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

;создание поля ввода
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

;создание текстовой метки
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
