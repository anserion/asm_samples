; checkbox messages
; =================

BST_UNCHECKED equ 00h
BST_CHECKED equ 01h
BST_INDETERMINATE equ 02h
BST_PUSHED equ 04h

; Mouse button messages
; =====================

TPM_LEFTBUTTON		equ	0h
TPM_RIGHTBUTTON		equ	2h
TPM_LEFTALIGN		equ	0h
TPM_CENTERALIGN		equ	4h
TPM_RIGHTALIGN		equ	8h


; Icon notify messages
; ====================

NIM_ADD			equ	0h
NIM_MODIFY		equ	1h
NIM_DELETE		equ	2h

; Icon notify flags
; =================

NIF_MESSAGE		equ	1h
NIF_ICON		equ	2h
NIF_TIP			equ	4h

; button control messages
; =======================

BM_GETCHECK          EQU	00F0h
BM_SETCHECK          EQU	00F1h
BM_GETSTATE          EQU	00F2h
BM_SETSTATE          EQU	00F3h
BM_SETSTYLE          EQU	00F4h
BM_CLICK             EQU	00F5h
BM_GETIMAGE          EQU	00F6h
BM_SETIMAGE          EQU	00F7h

;------------------------------------------------------------------------------

; ============================
; button control notifications
; ============================

BN_CLICKED           EQU	0000h
BN_PAINT             EQU	0001h
BN_HILITE            EQU	0002h
BN_UNHILITE          EQU	0003h
BN_DISABLE           EQU	0004h
BN_DOUBLECLICKED     EQU	0005h
BN_SETFOCUS          EQU	0006h
BN_KILLFOCUS         EQU	0007h

BN_PUSHED            EQU	BN_HILITE
BN_UNPUSHED          EQU	BN_UNHILITE
BN_DBLCLK            EQU	BN_DOUBLECLICKED


;------------------------------------------------------------------------------
;
; ==================
; combo box messages
; ==================
;
CB_GETEDITSEL        EQU	0140h
CB_LIMITTEXT         EQU	0141h
CB_SETEDITSEL        EQU	0142h
CB_ADDSTRING         EQU	0143h
CB_DELETESTRING      EQU	0144h
CB_DIR               EQU	0145h
CB_GETCOUNT          EQU	0146h
CB_GETCURSEL         EQU	0147h
CB_GETLBTEXT         EQU	0148h
CB_GETLBTEXTLEN      EQU	0149h
CB_INSERTSTRING      EQU	014Ah
CB_RESETCONTENT      EQU	014Bh
CB_FINDSTRING        EQU	014Ch
CB_SELECTSTRING      EQU	014Dh
CB_SETCURSEL         EQU	014Eh
CB_SHOWDROPDOWN      EQU	014Fh
CB_GETITEMDATA       EQU	0150h
CB_SETITEMDATA       EQU	0151h
CB_GETDROPPEDCONTROLRECT EQU	0152h
CB_SETITEMHEIGHT     EQU	0153h
CB_GETITEMHEIGHT     EQU	0154h
CB_SETEXTENDEDUI     EQU	0155h
CB_GETEXTENDEDUI     EQU	0156h
CB_GETDROPPEDSTATE   EQU	0157h
CB_FINDSTRINGEXACT   EQU	0158h
CB_SETLOCALE         EQU	0159h
CB_GETLOCALE         EQU	015Ah
CB_GETTOPINDEX       EQU	015Bh
CB_SETTOPINDEX       EQU	015Ch
CB_GETHORIZONTALEXTENT EQU	015Dh
CB_SETHORIZONTALEXTENT EQU	015Eh
CB_GETDROPPEDWIDTH   EQU	015Fh
CB_SETDROPPEDWIDTH   EQU	0160h
CB_INITSTORAGE       EQU	0161h
CB_MSGMAX            EQU	0162h

CB_OKAY              EQU	0
CB_ERR               EQU	-1
CB_ERRSPACE          EQU	-2
; combo box notification codes
; ============================

CBN_ERRSPACE         EQU	-1
CBN_SELCHANGE        EQU	1
CBN_DBLCLK           EQU	2
CBN_SETFOCUS         EQU	3
CBN_KILLFOCUS        EQU	4
CBN_EDITCHANGE       EQU	5
CBN_EDITUPDATE       EQU	6
CBN_DROPDOWN         EQU	7
CBN_CLOSEUP          EQU	8
CBN_SELENDOK         EQU	9
CBN_SELENDCANCEL     EQU	10
; edit control messages
; =====================

EM_GETSEL            EQU	00B0h
EM_SETSEL            EQU	00B1h
EM_GETRECT           EQU	00B2h
EM_SETRECT           EQU	00B3h
EM_SETRECTNP         EQU	00B4h
EM_SCROLL            EQU	00B5h
EM_LINESCROLL        EQU	00B6h
EM_SCROLLCARET       EQU	00B7h
EM_GETMODIFY         EQU	00B8h
EM_SETMODIFY         EQU	00B9h
EM_GETLINECOUNT      EQU	00BAh
EM_LINEINDEX         EQU	00BBh
EM_SETHANDLE         EQU	00BCh
EM_GETHANDLE         EQU	00BDh
EM_GETTHUMB          EQU	00BEh
EM_LINELENGTH        EQU	00C1h
EM_REPLACESEL        EQU	00C2h
EM_GETLINE           EQU	00C4h
EM_LIMITTEXT         EQU	00C5h
EM_CANUNDO           EQU	00C6h
EM_UNDO              EQU	00C7h
EM_FMTLINES          EQU	00C8h
EM_LINEFROMCHAR      EQU	00C9h
EM_SETTABSTOPS       EQU	00CBh
EM_SETPASSWORDCHAR   EQU	00CCh
EM_EMPTYUNDOBUFFER   EQU	00CDh
EM_GETFIRSTVISIBLELINE EQU	00CEh
EM_SETREADONLY       EQU	00CFh
EM_SETWORDBREAKPROC  EQU	00D0h
EM_GETWORDBREAKPROC  EQU	00D1h
EM_GETPASSWORDCHAR   EQU	00D2h
EM_SETMARGINS        EQU	00D3h
EM_GETMARGINS        EQU	00D4h
EM_GETLIMITTEXT      EQU	00D5h
EM_POSFROMCHAR       EQU	00D6h
EM_CHARFROMPOS       EQU	00D7h

EM_SETLIMITTEXT      EQU	EM_LIMITTEXT
;
;------------------------------------------------------------------------------
;
; ==========================
; edit control notifications
; ==========================
;
EN_SETFOCUS          EQU	0100h
EN_KILLFOCUS         EQU	0200h
EN_CHANGE            EQU	0300h
EN_UPDATE            EQU	0400h
EN_ERRSPACE          EQU	0500h
EN_MAXTEXT           EQU	0501h
EN_HSCROLL           EQU	0601h
EN_VSCROLL           EQU	0602h
; listbox messages
; ================

LB_ADDSTRING         EQU	0180h
LB_INSERTSTRING      EQU	0181h
LB_DELETESTRING      EQU	0182h
LB_SELITEMRANGEEX    EQU	0183h
LB_RESETCONTENT      EQU	0184h
LB_SETSEL            EQU	0185h
LB_SETCURSEL         EQU	0186h
LB_GETSEL            EQU	0187h
LB_GETCURSEL         EQU	0188h
LB_GETTEXT           EQU	0189h
LB_GETTEXTLEN        EQU	018Ah
LB_GETCOUNT          EQU	018Bh
LB_SELECTSTRING      EQU	018Ch
LB_DIR               EQU	018Dh
LB_GETTOPINDEX       EQU	018Eh
LB_FINDSTRING        EQU	018Fh
LB_GETSELCOUNT       EQU	0190h
LB_GETSELITEMS       EQU	0191h
LB_SETTABSTOPS       EQU	0192h
LB_GETHORIZONTALEXTENT EQU	0193h
LB_SETHORIZONTALEXTENT EQU	0194h
LB_SETCOLUMNWIDTH    EQU	0195h
LB_ADDFILE           EQU	0196h
LB_SETTOPINDEX       EQU	0197h
LB_GETITEMRECT       EQU	0198h
LB_GETITEMDATA       EQU	0199h
LB_SETITEMDATA       EQU	019Ah
LB_SELITEMRANGE      EQU	019Bh
LB_SETANCHORINDEX    EQU	019Ch
LB_GETANCHORINDEX    EQU	019Dh
LB_SETCARETINDEX     EQU	019Eh
LB_GETCARETINDEX     EQU	019Fh
LB_SETITEMHEIGHT     EQU	01A0h
LB_GETITEMHEIGHT     EQU	01A1h
LB_FINDSTRINGEXACT   EQU	01A2h
LB_SETLOCALE         EQU	01A5h
LB_GETLOCALE         EQU	01A6h
LB_SETCOUNT          EQU	01A7h
LB_INITSTORAGE       EQU	01A8h
LB_ITEMFROMPOINT     EQU	01A9h
LB_MSGMAX            EQU	01B0h

;------------------------------------------------------------------------------

; =====================
; listbox return values
; =====================

LB_OKAY              EQU	0
LB_ERR               EQU	-1
LB_ERRSPACE          EQU	-2

;------------------------------------------------------------------------------

; ==========================
; listbox notification codes
; ==========================

LBN_ERRSPACE         EQU	-2
LBN_SELCHANGE        EQU	1
LBN_DBLCLK           EQU	2
LBN_SELCANCEL        EQU	3
LBN_SETFOCUS         EQU	4
LBN_KILLFOCUS        EQU	5
; list view messages
; ==================

LVM_FIRST            EQU	1000h

LVM_GETBKCOLOR       EQU	LVM_FIRST+000
LVM_SETBKCOLOR       EQU	LVM_FIRST+001
LVM_GETIMAGELIST     EQU	LVM_FIRST+002
LVM_SETIMAGELIST     EQU	LVM_FIRST+003
LVM_GETITEMCOUNT     EQU	LVM_FIRST+004
LVM_GETITEMA         EQU	LVM_FIRST+005
LVM_SETITEMA         EQU	LVM_FIRST+006
LVM_INSERTITEMA      EQU	LVM_FIRST+007
LVM_DELETEITEM       EQU	LVM_FIRST+008
LVM_DELETEALLITEMS   EQU	LVM_FIRST+009
LVM_GETCALLBACKMASK  EQU	LVM_FIRST+010
LVM_SETCALLBACKMASK  EQU	LVM_FIRST+011
LVM_GETNEXTITEM      EQU	LVM_FIRST+012
LVM_FINDITEMA        EQU	LVM_FIRST+013
LVM_GETITEMRECT      EQU	LVM_FIRST+014
LVM_SETITEMPOSITION  EQU	LVM_FIRST+015
LVM_GETITEMPOSITION  EQU	LVM_FIRST+016
LVM_GETSTRINGWIDTHA  EQU	LVM_FIRST+017
LVM_HITTEST          EQU	LVM_FIRST+018
LVM_ENSUREVISIBLE    EQU	LVM_FIRST+019
LVM_SCROLL           EQU	LVM_FIRST+020
LVM_REDRAWITEMS      EQU	LVM_FIRST+021
LVM_ARRANGE          EQU	LVM_FIRST+022
LVM_EDITLABELA       EQU	LVM_FIRST+023
LVM_GETEDITCONTROL   EQU	LVM_FIRST+024
LVM_GETCOLUMNA       EQU	LVM_FIRST+025
LVM_SETCOLUMNA       EQU	LVM_FIRST+026
LVM_INSERTCOLUMNA    EQU	LVM_FIRST+027
LVM_DELETECOLUMN     EQU	LVM_FIRST+028
LVM_GETCOLUMNWIDTH   EQU	LVM_FIRST+029
LVM_SETCOLUMNWIDTH   EQU	LVM_FIRST+030
LVM_CREATEDRAGIMAGE  EQU	LVM_FIRST+033
LVM_GETVIEWRECT      EQU	LVM_FIRST+034
LVM_GETTEXTCOLOR     EQU	LVM_FIRST+035
LVM_SETTEXTCOLOR     EQU	LVM_FIRST+036
LVM_GETTEXTBKCOLOR   EQU	LVM_FIRST+037
LVM_SETTEXTBKCOLOR   EQU	LVM_FIRST+038
LVM_GETTOPINDEX      EQU	LVM_FIRST+039
LVM_GETCOUNTPERPAGE  EQU	LVM_FIRST+040
LVM_GETORIGIN        EQU	LVM_FIRST+041
LVM_UPDATE           EQU	LVM_FIRST+042
LVM_SETITEMSTATE     EQU	LVM_FIRST+043
LVM_GETITEMSTATE     EQU	LVM_FIRST+044
LVM_GETITEMTEXTA     EQU	LVM_FIRST+045
LVM_SETITEMTEXTA     EQU	LVM_FIRST+046
LVM_SETITEMCOUNT     EQU	LVM_FIRST+047
LVM_SORTITEMS        EQU	LVM_FIRST+048
LVM_SETITEMPOSITION32 EQU	LVM_FIRST+049
LVM_GETSELECTEDCOUNT EQU	LVM_FIRST+050
LVM_GETITEMSPACING   EQU	LVM_FIRST+051
LVM_GETISEARCHSTRINGA EQU	LVM_FIRST+052

LVM_GETITEMW         EQU	LVM_FIRST+075
LVM_SETITEMW         EQU	LVM_FIRST+076
LVM_INSERTITEMW      EQU	LVM_FIRST+077
LVM_FINDITEMW        EQU	LVM_FIRST+083
LVM_GETSTRINGWIDTHW  EQU	LVM_FIRST+087
LVM_GETCOLUMNW       EQU	LVM_FIRST+095
LVM_SETCOLUMNW       EQU	LVM_FIRST+096
LVM_INSERTCOLUMNW    EQU	LVM_FIRST+097
LVM_GETITEMTEXTW     EQU	LVM_FIRST+115
LVM_SETITEMTEXTW     EQU	LVM_FIRST+116
LVM_GETISEARCHSTRINGW EQU	LVM_FIRST+117
LVM_EDITLABELW       EQU	LVM_FIRST+118
;
%ifdef UniCode
LVM_GETITEM          EQU	LVM_GETITEMW
LVM_SETITEM          EQU	LVM_SETITEMW
LVM_INSERTITEM       EQU	LVM_INSERTITEMW
LVM_FINDITEM         EQU	LVM_FINDITEMW
LVM_GETSTRINGWIDTH   EQU	LVM_GETSTRINGWIDTHW
LVM_GETCOLUMN        EQU	LVM_GETCOLUMNW
LVM_SETCOLUMN        EQU	LVM_SETCOLUMNW
LVM_INSERTCOLUMN     EQU	LVM_INSERTCOLUMNW
LVM_GETITEMTEXT      EQU	LVM_GETITEMTEXTW
LVM_SETITEMTEXT      EQU	LVM_SETITEMTEXTW
LVM_GETISEARCHSTRING EQU	LVM_GETISEARCHSTRINGW
LVM_EDITLABEL        EQU	LVM_EDITLABELW
%else
LVM_GETITEM          EQU	LVM_GETITEMA
LVM_SETITEM          EQU	LVM_SETITEMA
LVM_INSERTITEM       EQU	LVM_INSERTITEMA
LVM_FINDITEM         EQU	LVM_FINDITEMA
LVM_GETSTRINGWIDTH   EQU	LVM_GETSTRINGWIDTHA
LVM_GETCOLUMN        EQU	LVM_GETCOLUMNA
LVM_SETCOLUMN        EQU	LVM_SETCOLUMNA
LVM_INSERTCOLUMN     EQU	LVM_INSERTCOLUMNA
LVM_GETITEMTEXT      EQU	LVM_GETITEMTEXTA
LVM_SETITEMTEXT      EQU	LVM_SETITEMTEXTA
LVM_GETISEARCHSTRING EQU	LVM_GETISEARCHSTRINGA
LVM_EDITLABEL        EQU	LVM_EDITLABELA
%endif

;------------------------------------------------------------------------------

; =======================
; list view notifications
; =======================

LVN_FIRST            EQU	-100
LVN_LAST             EQU	LVN_FIRST-99

LVN_ITEMCHANGING     EQU	LVN_FIRST-00
LVN_ITEMCHANGED      EQU	LVN_FIRST-01
LVN_INSERTITEM       EQU	LVN_FIRST-02
LVN_DELETEITEM       EQU	LVN_FIRST-03
LVN_DELETEALLITEMS   EQU	LVN_FIRST-04
LVN_BEGINLABELEDITA  EQU	LVN_FIRST-05
LVN_ENDLABELEDITA    EQU	LVN_FIRST-06
LVN_COLUMNCLICK      EQU	LVN_FIRST-08
LVN_BEGINDRAG        EQU	LVN_FIRST-09
LVN_BEGINRDRAG       EQU	LVN_FIRST-11
LVN_GETDISPINFOA     EQU	LVN_FIRST-50
LVN_SETDISPINFOA     EQU	LVN_FIRST-51

LVN_BEGINLABELEDITW  EQU	LVN_FIRST-75
LVN_ENDLABELEDITW    EQU	LVN_FIRST-76
LVN_GETDISPINFOW     EQU	LVN_FIRST-77
LVN_SETDISPINFOW     EQU	LVN_FIRST-78

%ifdef  UniCode
LVN_BEGINLABELEDIT   EQU	LVN_BEGINLABELEDITW
LVN_ENDLABELEDIT     EQU	LVN_ENDLABELEDITW
LVN_GETDISPINFO      EQU	LVN_GETDISPINFOW
LVN_SETDISPINFO      EQU	LVN_SETDISPINFOW
%else
LVN_BEGINLABELEDIT   EQU	LVN_BEGINLABELEDITA
LVN_ENDLABELEDIT     EQU	LVN_ENDLABELEDITA
LVN_GETDISPINFO      EQU	LVN_GETDISPINFOA
LVN_SETDISPINFO      EQU	LVN_SETDISPINFOA
%endif
; status bar messages
; ===================

WM_USER              EQU	0400h

SB_SETTEXTA          EQU	WM_USER+01
SB_GETTEXTA          EQU	WM_USER+02
SB_GETTEXTLENGTHA    EQU	WM_USER+03
SB_SETPARTS          EQU	WM_USER+04
SB_GETPARTS          EQU	WM_USER+06
SB_GETBORDERS        EQU	WM_USER+07
SB_SETMINHEIGHT      EQU	WM_USER+08
SB_SIMPLE            EQU	WM_USER+09
SB_GETRECT           EQU	WM_USER+10
SB_SETTEXTW          EQU	WM_USER+11
SB_GETTEXTLENGTHW    EQU	WM_USER+12
SB_GETTEXTW          EQU	WM_USER+13

%ifdef  UniCode
SB_GETTEXT           EQU	SB_GETTEXTW
SB_SETTEXT           EQU	SB_SETTEXTW
SB_GETTEXTLENGTH     EQU	SB_GETTEXTLENGTHW
%else
SB_GETTEXT           EQU	SB_GETTEXTA
SB_SETTEXT           EQU	SB_SETTEXTA
SB_GETTEXTLENGTH     EQU	SB_GETTEXTLENGTHA
%endif

;------------------------------------------------------------------------------

; ===================
; scroll bar messages
; ===================

SBM_SETPOS           EQU	00E0h
SBM_GETPOS           EQU	00E1h
SBM_SETRANGE         EQU	00E2h
SBM_GETRANGE         EQU	00E3h
SBM_ENABLE_ARROWS    EQU	00E4h
SBM_SETRANGEREDRAW   EQU	00E6h
SBM_SETSCROLLINFO    EQU	00E9h
SBM_GETSCROLLINFO    EQU	00EAh
; toolbar messages
; ================

TB_ENABLEBUTTON      EQU	WM_USER+01
TB_CHECKBUTTON       EQU	WM_USER+02
TB_PRESSBUTTON       EQU	WM_USER+03
TB_HIDEBUTTON        EQU	WM_USER+04
TB_INDETERMINATE     EQU	WM_USER+05
TB_ISBUTTONENABLED   EQU	WM_USER+09
TB_ISBUTTONCHECKED   EQU	WM_USER+10
TB_ISBUTTONPRESSED   EQU	WM_USER+11
TB_ISBUTTONHIDDEN    EQU	WM_USER+12
TB_ISBUTTONINDETERMINATE EQU	WM_USER+13
TB_SETSTATE          EQU	WM_USER+17
TB_GETSTATE          EQU	WM_USER+18
TB_ADDBITMAP         EQU	WM_USER+19
TB_ADDBUTTONS        EQU	WM_USER+20
TB_INSERTBUTTON      EQU	WM_USER+21
TB_DELETEBUTTON      EQU	WM_USER+22
TB_GETBUTTON         EQU	WM_USER+23
TB_BUTTONCOUNT       EQU	WM_USER+24
TB_COMMANDTOINDEX    EQU	WM_USER+25
TB_SAVERESTOREA      EQU	WM_USER+26
TB_CUSTOMIZE         EQU	WM_USER+27
TB_ADDSTRINGA        EQU	WM_USER+28
TB_GETITEMRECT       EQU	WM_USER+29
TB_BUTTONSTRUCTSIZE  EQU	WM_USER+30
TB_SETBUTTONSIZE     EQU	WM_USER+31
TB_SETBITMAPSIZE     EQU	WM_USER+32
TB_AUTOSIZE          EQU	WM_USER+33
TB_GETTOOLTIPS       EQU	WM_USER+35
TB_SETTOOLTIPS       EQU	WM_USER+36
TB_SETPARENT         EQU	WM_USER+37
TB_SETROWS           EQU	WM_USER+39
TB_GETROWS           EQU	WM_USER+40
TB_GETBITMAPFLAGS    EQU	WM_USER+41
TB_SETCMDID          EQU	WM_USER+42
TB_CHANGEBITMAP      EQU	WM_USER+43
TB_GETBITMAP         EQU	WM_USER+44
TB_GETBUTTONTEXTA    EQU	WM_USER+45
TB_REPLACEBITMAP     EQU	WM_USER+46
;
TB_GETBUTTONTEXTW    EQU	WM_USER+75
TB_SAVERESTOREW      EQU	WM_USER+76
TB_ADDSTRINGW        EQU	WM_USER+77

%ifdef  UniCode
TB_GETBUTTONTEXT     EQU	TB_GETBUTTONTEXTW
TB_SAVERESTORE       EQU	TB_SAVERESTOREW
TB_ADDSTRING         EQU	TB_ADDSTRINGW
%else
TB_GETBUTTONTEXT     EQU	TB_GETBUTTONTEXTA
TB_SAVERESTORE       EQU	TB_SAVERESTOREA
TB_ADDSTRING         EQU	TB_ADDSTRINGA
%endif

;------------------------------------------------------------------------------

; =====================
; toolbar notifications
; =====================

TBN_FIRST            EQU	-700
TBN_LAST             EQU	TBN_FIRST-20

TBN_GETBUTTONINFOA   EQU	TBN_FIRST-00
TBN_BEGINDRAG        EQU	TBN_FIRST-01
TBN_ENDDRAG          EQU	TBN_FIRST-02
TBN_BEGINADJUST      EQU	TBN_FIRST-03
TBN_ENDADJUST        EQU	TBN_FIRST-04
TBN_RESET            EQU	TBN_FIRST-05
TBN_QUERYINSERT      EQU	TBN_FIRST-06
TBN_QUERYDELETE      EQU	TBN_FIRST-07
TBN_TOOLBARCHANGE    EQU	TBN_FIRST-08
TBN_CUSTHELP         EQU	TBN_FIRST-09
TBN_GETBUTTONINFOW   EQU	TBN_FIRST-20
; Sent as WM_NOTIFY messages.
; (Unicode should be implemented here. See CommCtrl.h).

TTN_FIRST            EQU	-520
TTN_LAST             EQU	-549

TTN_NEEDTEXTA        EQU	TTN_FIRST-0           ;Retrieves text for a tool
TTN_SHOW             EQU	TTN_FIRST-1           ;Tooltip about to be displayed.
TTN_POP              EQU	TTN_FIRST-2           ;Tooltip about to be hidden
TTN_NEEDTEXTW        EQU	TTN_FIRST-10          ;Retrieves text for a tool

%ifdef UniCode
TTN_NEEDTEXT         EQU	TTN_NEEDTEXTW       ;Retrieves text for a tool
%else
TTN_NEEDTEXT         EQU	TTN_NEEDTEXTA       ;Retrieves text for a tool
%endif

;------------------------------------------------------------------------------

; ==================
; tree view messages
; ==================

TVM_FIRST            EQU	1100h
TV_FIRST             EQU	TVM_FIRST

TVM_INSERTITEMA      EQU	TVM_FIRST+00
TVM_DELETEITEM       EQU	TVM_FIRST+01
TVM_EXPAND           EQU	TVM_FIRST+02
TVM_GETITEMRECT      EQU	TVM_FIRST+04
TVM_GETCOUNT         EQU	TVM_FIRST+05
TVM_GETINDENT        EQU	TVM_FIRST+06
TVM_SETINDENT        EQU	TVM_FIRST+07
TVM_GETIMAGELIST     EQU	TVM_FIRST+08
TVM_SETIMAGELIST     EQU	TVM_FIRST+09
TVM_GETNEXTITEM      EQU	TVM_FIRST+10
TVM_SELECTITEM       EQU	TVM_FIRST+11
TVM_GETITEMA         EQU	TVM_FIRST+12
TVM_SETITEMA         EQU	TVM_FIRST+13
TVM_EDITLABELA       EQU	TVM_FIRST+14
TVM_GETEDITCONTROL   EQU	TVM_FIRST+15
TVM_GETVISIBLECOUNT  EQU	TVM_FIRST+16
TVM_HITTEST          EQU	TVM_FIRST+17
TVM_CREATEDRAGIMAGE  EQU	TVM_FIRST+18
TVM_SORTCHILDREN     EQU	TVM_FIRST+19
TVM_ENSUREVISIBLE    EQU	TVM_FIRST+20
TVM_SORTCHILDRENCB   EQU	TVM_FIRST+21
TVM_ENDEDITLABELNOW  EQU	TVM_FIRST+22
TVM_GETISEARCHSTRINGA EQU	TVM_FIRST+23
;
TVM_INSERTITEMW      EQU	TVM_FIRST+50
TVM_GETITEMW         EQU	TVM_FIRST+62
TVM_SETITEMW         EQU	TVM_FIRST+63
TVM_GETISEARCHSTRINGW EQU	TVM_FIRST+64
TVM_EDITLABELW       EQU	TVM_FIRST+65

%ifdef UniCode
TVM_INSERTITEM       EQU	TVM_INSERTITEMW
TVM_GETITEM          EQU	TVM_GETITEMW
TVM_SETITEM          EQU	TVM_SETITEMW
TVM_GETISEARCHSTRING EQU	TVM_GETISEARCHSTRINGW
TVM_EDITLABEL        EQU	TVM_EDITLABELW
%else
TVM_INSERTITEM       EQU	TVM_INSERTITEMA
TVM_GETITEM          EQU	TVM_GETITEMA
TVM_SETITEM          EQU	TVM_SETITEMA
TVM_GETISEARCHSTRING EQU	TVM_GETISEARCHSTRINGA
TVM_EDITLABEL        EQU	TVM_EDITLABELA
%endif

;------------------------------------------------------------------------------

; =======================
; tree view notifications
; =======================

TVN_FIRST            EQU	-400
TVN_LAST             EQU	TVN_FIRST-99

TVN_SELCHANGINGA     EQU	TVN_FIRST-01
TVN_SELCHANGEDA      EQU	TVN_FIRST-02
TVN_GETDISPINFOA     EQU	TVN_FIRST-03
TVN_SETDISPINFOA     EQU	TVN_FIRST-04
TVN_ITEMEXPANDINGA   EQU	TVN_FIRST-05
TVN_ITEMEXPANDEDA    EQU	TVN_FIRST-06
TVN_BEGINDRAGA       EQU	TVN_FIRST-07
TVN_BEGINRDRAGA      EQU	TVN_FIRST-08
TVN_DELETEITEMA      EQU	TVN_FIRST-09
TVN_ENDLABELEDITA    EQU	TVN_FIRST-11
TVN_KEYDOWN          EQU	TVN_FIRST-12

TVN_SELCHANGINGW     EQU	TVN_FIRST-50
TVN_SELCHANGEDW      EQU	TVN_FIRST-51
TVN_GETDISPINFOW     EQU	TVN_FIRST-52
TVN_SETDISPINFOW     EQU	TVN_FIRST-53
TVN_ITEMEXPANDINGW   EQU	TVN_FIRST-54
TVN_ITEMEXPANDEDW    EQU	TVN_FIRST-55
TVN_BEGINDRAGW       EQU	TVN_FIRST-56
TVN_BEGINRDRAGW      EQU	TVN_FIRST-57
TVN_DELETEITEMW      EQU	TVN_FIRST-58
TVN_BEGINLABELEDITA  EQU	TVN_FIRST-10
TVN_BEGINLABELEDITW  EQU	TVN_FIRST-59
TVN_ENDLABELEDITW    EQU	TVN_FIRST-60

%ifdef UniCode
TVN_SELCHANGING      EQU	TVN_SELCHANGINGW
TVN_SELCHANGED       EQU	TVN_SELCHANGEDW
TVN_GETDISPINFO      EQU	TVN_GETDISPINFOW
TVN_SETDISPINFO      EQU	TVN_SETDISPINFOW
TVN_ITEMEXPANDING    EQU	TVN_ITEMEXPANDINGW
TVN_ITEMEXPANDED     EQU	TVN_ITEMEXPANDEDW
TVN_BEGINDRAG        EQU	TVN_BEGINDRAGW
TVN_BEGINRDRAG       EQU	TVN_BEGINRDRAGW
TVN_DELETEITEM       EQU	TVN_DELETEITEMW
TVN_BEGINLABELEDIT   EQU	TVN_BEGINLABELEDITW
TVN_ENDLABELEDIT     EQU	TVN_ENDLABELEDITW
%else
TVN_SELCHANGING      EQU	TVN_SELCHANGINGA
TVN_SELCHANGED       EQU	TVN_SELCHANGEDA
TVN_GETDISPINFO      EQU	TVN_GETDISPINFOA
TVN_SETDISPINFO      EQU	TVN_SETDISPINFOA
TVN_ITEMEXPANDING    EQU	TVN_ITEMEXPANDINGA
TVN_ITEMEXPANDED     EQU	TVN_ITEMEXPANDEDA
TVN_BEGINDRAG        EQU	TVN_BEGINDRAGA
TVN_BEGINRDRAG       EQU	TVN_BEGINRDRAGA
TVN_DELETEITEM       EQU	TVN_DELETEITEMA
TVN_BEGINLABELEDIT   EQU	TVN_BEGINLABELEDITA
TVN_ENDLABELEDIT     EQU	TVN_ENDLABELEDITA
%endif
; window messages
; ===============

WM_NULL              EQU	0000h
WM_CREATE            EQU	0001h
WM_DESTROY           EQU	0002h
WM_MOVE              EQU	0003h
WM_SIZE              EQU	0005h
WM_ACTIVATE          EQU	0006h
WM_SETFOCUS          EQU	0007h
WM_KILLFOCUS         EQU	0008h
WM_ENABLE            EQU	000Ah
WM_SETREDRAW         EQU	000Bh
WM_SETTEXT           EQU	000Ch
WM_GETTEXT           EQU	000Dh
WM_GETTEXTLENGTH     EQU	000Eh
WM_PAINT             EQU	000Fh
WM_CLOSE             EQU	0010h
WM_QUERYENDSESSION   EQU	0011h
WM_QUIT              EQU	0012h
WM_QUERYOPEN         EQU	0013h
WM_ERASEBKGND        EQU	0014h
WM_SYSCOLORCHANGE    EQU	0015h
WM_ENDSESSION        EQU	0016h
WM_SHOWWINDOW        EQU	0018h
WM_WININICHANGE      EQU	001Ah
WM_SETTINGCHANGE     EQU	WM_WININICHANGE
WM_DEVMODECHANGE     EQU	001Bh
WM_ACTIVATEAPP       EQU	001Ch
WM_FONTCHANGE        EQU	001Dh
WM_TIMECHANGE        EQU	001Eh
WM_CANCELMODE        EQU	001Fh
WM_SETCURSOR         EQU	0020h
WM_MOUSEACTIVATE     EQU	0021h
WM_CHILDACTIVATE     EQU	0022h
WM_QUEUESYNC         EQU	0023h
WM_GETMINMAXINFO     EQU	0024h
WM_PAINTICON         EQU	0026h
WM_ICONERASEBKGND    EQU	0027h
WM_NEXTDLGCTL        EQU	0028h
WM_SPOOLERSTATUS     EQU	002Ah
WM_DRAWITEM          EQU	002Bh
WM_MEASUREITEM       EQU	002Ch
WM_DELETEITEM        EQU	002Dh
WM_VKEYTOITEM        EQU	002Eh
WM_CHARTOITEM        EQU	002Fh
WM_SETFONT           EQU	0030h
WM_GETFONT           EQU	0031h
WM_SETHOTKEY         EQU	0032h
WM_GETHOTKEY         EQU	0033h
WM_QUERYDRAGICON     EQU	0037h
WM_COMPAREITEM       EQU	0039h
WM_COMPACTING        EQU	0041h
WM_COMMNOTIFY        EQU	0044h      ;no longer suported
WM_WINDOWPOSCHANGING EQU	0046h
WM_WINDOWPOSCHANGED  EQU	0047h
WM_POWER             EQU	0048h
WM_COPYDATA          EQU	004Ah
WM_CANCELJOURNAL     EQU	004Bh
WM_NOTIFY            EQU	004Eh
WM_INPUTLANGCHANGEREQUEST EQU	0050h
WM_INPUTLANGCHANGE   EQU	0051h
WM_TCARD             EQU	0052h
WM_HELP              EQU	0053h
WM_USERCHANGED       EQU	0054h
WM_NOTIFYFORMAT      EQU	0055h
WM_CONTEXTMENU       EQU	007Bh
WM_STYLECHANGING     EQU	007Ch
WM_STYLECHANGED      EQU	007Dh
WM_DISPLAYCHANGE     EQU	007Eh
WM_GETICON           EQU	007Fh
WM_SETICON           EQU	0080h
WM_NCCREATE          EQU	0081h
WM_NCDESTROY         EQU	0082h
WM_NCCALCSIZE        EQU	0083h
WM_NCHITTEST         EQU	0084h
WM_NCPAINT           EQU	0085h
WM_NCACTIVATE        EQU	0086h
WM_GETDLGCODE        EQU	0087h

WM_NCMOUSEMOVE       EQU	00A0h
WM_NCLBUTTONDOWN     EQU	00A1h
WM_NCLBUTTONUP       EQU	00A2h
WM_NCLBUTTONDBLCLK   EQU	00A3h
WM_NCRBUTTONDOWN     EQU	00A4h
WM_NCRBUTTONUP       EQU	00A5h
WM_NCRBUTTONDBLCLK   EQU	00A6h
WM_NCMBUTTONDOWN     EQU	00A7h
WM_NCMBUTTONUP       EQU	00A8h
WM_NCMBUTTONDBLCLK   EQU	00A9h

WM_KEYFIRST          EQU	0100h
WM_KEYDOWN           EQU	0100h
WM_KEYUP             EQU	0101h
WM_CHAR              EQU	0102h
WM_DEADCHAR          EQU	0103h
WM_SYSKEYDOWN        EQU	0104h
WM_SYSKEYUP          EQU	0105h
WM_SYSCHAR           EQU	0106h
WM_SYSDEADCHAR       EQU	0107h
WM_KEYLAST           EQU	0108h

WM_IME_STARTCOMPOSITION EQU	010Dh
WM_IME_ENDCOMPOSITION EQU	010Eh
WM_IME_COMPOSITION   EQU	010Fh
WM_IME_KEYLAST       EQU	010Fh
WM_INITDIALOG        EQU	0110h
WM_COMMAND           EQU	0111h
WM_SYSCOMMAND        EQU	0112h
WM_TIMER             EQU	0113h
WM_HSCROLL           EQU	0114h
WM_VSCROLL           EQU	0115h
WM_INITMENU          EQU	0116h
WM_INITMENUPOPUP     EQU	0117h
WM_MENUSELECT        EQU	011Fh
WM_MENUCHAR          EQU	0120h
WM_ENTERIDLE         EQU	0121h
WM_CTLCOLORMSGBOX    EQU	0132h
WM_CTLCOLOREDIT      EQU	0133h
WM_CTLCOLORLISTBOX   EQU	0134h
WM_CTLCOLORBTN       EQU	0135h
WM_CTLCOLORDLG       EQU	0136h
WM_CTLCOLORSCROLLBAR EQU	0137h
WM_CTLCOLORSTATIC    EQU	0138h

WM_MOUSEFIRST        EQU	0200h
WM_MOUSEMOVE         EQU	0200h
WM_LBUTTONDOWN       EQU	0201h
WM_LBUTTONUP         EQU	0202h
WM_LBUTTONDBLCLK     EQU	0203h
WM_RBUTTONDOWN       EQU	0204h
WM_RBUTTONUP         EQU	0205h
WM_RBUTTONDBLCLK     EQU	0206h
WM_MBUTTONDOWN       EQU	0207h
WM_MBUTTONUP         EQU	0208h
WM_MBUTTONDBLCLK     EQU	0209h
WM_MOUSELAST         EQU	0209h

WM_PARENTNOTIFY      EQU	0210h
WM_ENTERMENULOOP     EQU	0211h
WM_EXITMENULOOP      EQU	0212h
WM_NEXTMENU          EQU	0213h
WM_SIZING            EQU	0214h
WM_CAPTURECHANGED    EQU	0215h
WM_MOVING            EQU	0216h
WM_POWERBROADCAST    EQU	0218h
WM_DEVICECHANGE      EQU	0219h
WM_MDICREATE         EQU	0220h
WM_MDIDESTROY        EQU	0221h
WM_MDIACTIVATE       EQU	0222h
WM_MDIRESTORE        EQU	0223h
WM_MDINEXT           EQU	0224h
WM_MDIMAXIMIZE       EQU	0225h
WM_MDITILE           EQU	0226h
WM_MDICASCADE        EQU	0227h
WM_MDIICONARRANGE    EQU	0228h
WM_MDIGETACTIVE      EQU	0229h
WM_MDISETMENU        EQU	0230h
WM_ENTERSIZEMOVE     EQU	0231h
WM_EXITSIZEMOVE      EQU	0232h
WM_DROPFILES         EQU	0233h
WM_MDIREFRESHMENU    EQU	0234h

WM_IME_SETCONTEXT    EQU	0281h
WM_IME_NOTIFY        EQU	0282h
WM_IME_CONTROL       EQU	0283h
WM_IME_COMPOSITIONFULL EQU	0284h
WM_IME_SELECT        EQU	0285h
WM_IME_CHAR          EQU	0286h
WM_IME_KEYDOWN       EQU	0290h
WM_IME_KEYUP         EQU	0291h

WM_CUT               EQU	0300h
WM_COPY              EQU	0301h
WM_PASTE             EQU	0302h
WM_CLEAR             EQU	0303h
WM_UNDO              EQU	0304h
WM_RENDERFORMAT      EQU	0305h
WM_RENDERALLFORMATS  EQU	0306h
WM_DESTROYCLIPBOARD  EQU	0307h
WM_DRAWCLIPBOARD     EQU	0308h
WM_PAINTCLIPBOARD    EQU	0309h
WM_VSCROLLCLIPBOARD  EQU	030Ah
WM_SIZECLIPBOARD     EQU	030Bh
WM_ASKCBFORMATNAME   EQU	030Ch
WM_CHANGECBCHAIN     EQU	030Dh
WM_HSCROLLCLIPBOARD  EQU	030Eh
WM_QUERYNEWPALETTE   EQU	030Fh
WM_PALETTEISCHANGING EQU	0310h
WM_PALETTECHANGED    EQU	0311h
WM_HOTKEY            EQU	0312h
WM_PRINT             EQU	0317h
WM_PRINTCLIENT       EQU	0318h

WM_HANDHELDFIRST     EQU	0358h
WM_HANDHELDLAST      EQU	035Fh

WM_AFXFIRST          EQU	0360h
WM_AFXLAST           EQU	037Fh

WM_PENWINFIRST       EQU	0380h
WM_PENWINLAST        EQU	038Fh

WM_DDE_FIRST         EQU	03E0h
WM_DDE_INITIATE      EQU	WM_DDE_FIRST
WM_DDE_TERMINATE     EQU	WM_DDE_FIRST+1
WM_DDE_ADVISE        EQU	WM_DDE_FIRST+2
WM_DDE_UNADVISE      EQU	WM_DDE_FIRST+3
WM_DDE_ACK           EQU	WM_DDE_FIRST+4
WM_DDE_DATA          EQU	WM_DDE_FIRST+5
WM_DDE_REQUEST       EQU	WM_DDE_FIRST+6
WM_DDE_POKE          EQU	WM_DDE_FIRST+7
WM_DDE_EXECUTE       EQU	WM_DDE_FIRST+8
WM_DDE_LAST          EQU	03E8h

WM_APP               EQU	8000h

; WM_SIZE wParam values
; =====================

SIZE_RESTORED        EQU	0
SIZE_MINIMIZED       EQU	1
SIZE_MAXIMIZED       EQU	2
SIZE_MAXSHOW         EQU	3
SIZE_MAXHIDE         EQU	4

SIZENORMAL           EQU	SIZE_RESTORED
SIZEICONIC           EQU	SIZE_MINIMIZED
SIZEFULLSCREEN       EQU	SIZE_MAXIMIZED
SIZEZOOMSHOW         EQU	SIZE_MAXSHOW
SIZEZOOMHIDE         EQU  SIZE_MAXHIDE

; mouse message key states
; ========================

MK_LBUTTON           EQU	0001h
MK_RBUTTON           EQU	0002h
MK_SHIFT             EQU	0004h
MK_CONTROL           EQU	0008h
MK_MBUTTON           EQU  0010h

; keyboard message lParam flags
; =============================

KF_EXTENDED          EQU	0100h
KF_DLGMODE           EQU	0800h
KF_MENUMODE          EQU	1000h
KF_ALTDOWN           EQU	2000h
KF_REPEAT            EQU	4000h
KF_UP                EQU  8000h

STRUC MINMAXINFO
   .ptReserved:          resd	2  ; x,y
   .ptMaxSize:           resd	2  ; x,y
   .ptMaxPosition:       resd	2  ; x,y
   .ptMinTrackSize:      resd	2  ; x,y
   .ptMaxTrackSize:      resd	2  ; x,y
ENDSTRUC

;------------------------------------------------------------------------------

STRUC MSG
   .hwnd:                resd	1	; HWND
   .message:             resd	1	; UINT
   .wParam:              resd	1	; WPARAM
   .lParam:              resd	1	; LPARAM
   .time:                resd	1	; DWORD
;   .x:                   resd   1       ; LONGINT
;   .y:                   resd   1       ; LONGINT
   .pt                   resd   1
ENDSTRUC


