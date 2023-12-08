;------------------------------------------------------------------------------
; color types
; ===========

COLOR_SCROLLBAR      EQU	0
COLOR_BACKGROUND     EQU	1
COLOR_ACTIVECAPTION  EQU	2
COLOR_INACTIVECAPTION EQU	3
COLOR_MENU           EQU	4
COLOR_WINDOW         EQU	5
COLOR_WINDOWFRAME    EQU	6
COLOR_MENUTEXT       EQU	7
COLOR_WINDOWTEXT     EQU	8
COLOR_CAPTIONTEXT    EQU	9
COLOR_ACTIVEBORDER   EQU	10
COLOR_INACTIVEBORDER EQU	11
COLOR_APPWORKSPACE   EQU	12
COLOR_HIGHLIGHT      EQU	13
COLOR_HIGHLIGHTTEXT  EQU	14
COLOR_BTNFACE        EQU	15
COLOR_BTNSHADOW      EQU	16
COLOR_GRAYTEXT       EQU	17
COLOR_BTNTEXT        EQU	18
COLOR_INACTIVECAPTIONTEXT EQU	19
COLOR_BTNHIGHLIGHT   EQU	20
COLOR_3DDKSHADOW     EQU	21
COLOR_3DLIGHT        EQU	22
COLOR_INFOTEXT       EQU	23
COLOR_INFOBK         EQU	24

COLOR_DESKTOP        EQU	COLOR_BACKGROUND
COLOR_3DFACE         EQU	COLOR_BTNFACE
COLOR_3DSHADOW       EQU	COLOR_BTNSHADOW
COLOR_3DHIGHLIGHT    EQU	COLOR_BTNHIGHLIGHT
COLOR_3DHILIGHT      EQU	COLOR_BTNHIGHLIGHT
COLOR_BTNHILIGHT     EQU	COLOR_BTNHIGHLIGHT

;------------------------------------------------------------------------------
; control color types
; ===================

CTLCOLOR_MSGBOX      EQU	0
CTLCOLOR_EDIT        EQU	1
CTLCOLOR_LISTBOX     EQU	2
CTLCOLOR_BTN         EQU	3
CTLCOLOR_DLG         EQU	4
CTLCOLOR_SCROLLBAR   EQU	5
CTLCOLOR_STATIC      EQU	6
CTLCOLOR_MAX         EQU	7


; ============
; class styles
; ============

CS_VREDRAW           EQU	00000001h
CS_HREDRAW           EQU	00000002h
CS_KEYCVTWINDOW      EQU	00000004h
CS_DBLCLKS           EQU	00000008h
CS_OWNDC             EQU	00000020h
CS_CLASSDC           EQU	00000040h
CS_PARENTDC          EQU	00000080h
CS_NOKEYCVT          EQU	00000100h
CS_NOCLOSE           EQU	00000200h
CS_SAVEBITS          EQU	00000800h
CS_BYTEALIGNCLIENT   EQU	00001000h
CS_BYTEALIGNWINDOW   EQU	00002000h
CS_GLOBALCLASS       EQU	00004000h
CS_IME               EQU	00010000h
; =======================
; DrawText() format flags
; =======================

DT_TOP               EQU	00000000h
DT_LEFT              EQU	00000000h
DT_CENTER            EQU	00000001h
DT_RIGHT             EQU	00000002h
DT_VCENTER           EQU	00000004h
DT_BOTTOM            EQU	00000008h
DT_WORDBREAK         EQU	00000010h
DT_SINGLELINE        EQU	00000020h
DT_EXPANDTABS        EQU	00000040h
DT_TABSTOP           EQU	00000080h
DT_NOCLIP            EQU	00000100h
DT_EXTERNALLEADING   EQU	00000200h
DT_CALCRECT          EQU	00000400h
DT_NOPREFIX          EQU	00000800h
DT_INTERNAL          EQU	00001000h
DT_EDITCONTROL       EQU	00002000h
DT_PATH_ELLIPSIS     EQU	00004000h
DT_END_ELLIPSIS      EQU	00008000h
DT_MODIFYSTRING      EQU	00010000h
DT_RTLREADING        EQU	00020000h
DT_WORD_ELLIPSIS     EQU	00040000h

; MessageBox() flags
; ==================

MB_OK                EQU	00000000h
MB_OKCANCEL          EQU	00000001h
MB_ABORTRETRYIGNORE  EQU	00000002h
MB_YESNOCANCEL       EQU	00000003h
MB_YESNO             EQU	00000004h
MB_RETRYCANCEL       EQU	00000005h

MB_ICONHAND          EQU	00000010h
MB_ICONQUESTION      EQU	00000020h
MB_ICONEXCLAMATION   EQU	00000030h
MB_ICONASTERISK      EQU	00000040h

MB_ICONWARNING       EQU	MB_ICONEXCLAMATION
MB_ICONERROR         EQU	MB_ICONHAND
MB_ICONINFORMATION   EQU	MB_ICONASTERISK
MB_ICONSTOP          EQU	MB_ICONHAND

MB_DEFBUTTON1        EQU	00000000h
MB_DEFBUTTON2        EQU	00000100h
MB_DEFBUTTON3        EQU	00000200h
MB_DEFBUTTON4        EQU	00000300h

MB_APPLMODAL         EQU	00000000h
MB_SYSTEMMODAL       EQU	00001000h
MB_TASKMODAL         EQU	00002000h
MB_HELP              EQU	00004000h
MB_TOPMOST           EQU	00040000h
MB_RIGHT             EQU	00080000h
MB_RTLREADING        EQU	00100000h


MB_NOFOCUS           EQU	00008000h
MB_SETFOREGROUND     EQU	00010000h
MB_DEFAULT_DESKTOP_ONLY EQU	00020000h
MB_SERVICE_NOTIFICATION EQU	00200000h  ;NT 4.0 and later (see MessageBox doc)

MB_TYPEMASK          EQU	0000000Fh
MB_USERICON          EQU	00000080h
MB_ICONMASK          EQU	000000F0h
MB_DEFMASK           EQU	00000F00h
MB_MODEMASK          EQU	00003000h
MB_MISCMASK          EQU	0000C000h

;------------------------------------------------------------------------------

; ==========
; menu flags
; ==========

MF_INSERT            EQU	00000000h
MF_CHANGE            EQU	00000080h
MF_APPEND            EQU	00000100h
MF_DELETE            EQU	00000200h
MF_REMOVE            EQU	00001000h

MF_BYCOMMAND         EQU	00000000h
MF_BYPOSITION        EQU	00000400h

MF_SEPARATOR         EQU	00000800h

MF_ENABLED           EQU	00000000h
MF_GRAYED            EQU	00000001h
MF_DISABLED          EQU	00000002h

MF_UNCHECKED         EQU	00000000h
MF_CHECKED           EQU	00000008h
MF_USECHECKBITMAPS   EQU	00000200h

MF_STRING            EQU	00000000h
MF_BITMAP            EQU	00000004h
MF_OWNERDRAW         EQU	00000100h

MF_POPUP             EQU	00000010h
MF_MENUBARBREAK      EQU	00000020h
MF_MENUBREAK         EQU	00000040h

MF_UNHILITE          EQU	00000000h
MF_HILITE            EQU	00000080h

MF_DEFAULT           EQU	00001000h
MF_SYSMENU           EQU	00002000h
MF_HELP              EQU	00004000h
MF_RIGHTJUSTIFY      EQU	00004000h

MF_MOUSESELECT       EQU	00008000h
MF_END               EQU	00000080h  ;obsolete

MFT_STRING           EQU	MF_STRING
MFT_BITMAP           EQU	MF_BITMAP
MFT_MENUBARBREAK     EQU	MF_MENUBARBREAK
MFT_MENUBREAK        EQU	MF_MENUBREAK
MFT_OWNERDRAW        EQU	MF_OWNERDRAW
MFT_RADIOCHECK       EQU	00000200h
MFT_SEPARATOR        EQU	MF_SEPARATOR
MFT_RIGHTORDER       EQU	00002000h
MFT_RIGHTJUSTIFY     EQU	MF_RIGHTJUSTIFY

MFS_GRAYED           EQU	00000003h
MFS_DISABLED         EQU	MFS_GRAYED
MFS_CHECKED          EQU	MF_CHECKED
MFS_HILITE           EQU	MF_HILITE
MFS_ENABLED          EQU	MF_ENABLED
MFS_UNCHECKED        EQU	MF_UNCHECKED
MFS_UNHILITE         EQU	MF_UNHILITE
MFS_DEFAULT          EQU	MF_DEFAULT
; ===================
; CombineRgn() styles
; ===================

RGN_AND              EQU	1
RGN_OR               EQU	2
RGN_XOR              EQU	3
RGN_DIFF             EQU	4
RGN_COPY             EQU	5
RGN_MIN              EQU	RGN_AND
RGN_MAX              EQU	RGN_COPY

; ==============
; toolbar styles
; ==============

TBSTYLE_BUTTON       EQU	0000h
TBSTYLE_SEP          EQU	0001h
TBSTYLE_CHECK        EQU	0002h
TBSTYLE_GROUP        EQU	0004h
TBSTYLE_TOOLTIPS     EQU	0100h
TBSTYLE_WRAPABLE     EQU	0200h
TBSTYLE_ALTDRAG      EQU	0400h
;
TBSTYLE_CHECKGROUP   EQU	TBSTYLE_GROUP+TBSTYLE_CHECK


WS_OVERLAPPED        EQU	000000000h
WS_TABSTOP           EQU	000010000h
WS_MAXIMIZEBOX       EQU	000010000h
WS_MINIMIZEBOX       EQU	000020000h
WS_GROUP             EQU	000020000h
WS_THICKFRAME        EQU	000040000h
WS_SYSMENU           EQU	000080000h
WS_HSCROLL           EQU	000100000h
WS_VSCROLL           EQU	000200000h
WS_DLGFRAME          EQU	000400000h
WS_BORDER            EQU	000800000h
WS_CAPTION           EQU	000C00000h
WS_MAXIMIZE          EQU	001000000h
WS_CLIPCHILDREN      EQU	002000000h
WS_CLIPSIBLINGS      EQU	004000000h
WS_DISABLED          EQU	008000000h
WS_VISIBLE           EQU	010000000h
WS_MINIMIZE          EQU	020000000h
WS_CHILD             EQU	040000000h
WS_POPUP             EQU	080000000h

WS_OVERLAPPEDWINDOW  EQU	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX
WS_POPUPWINDOW       EQU	WS_POPUP | WS_BORDER | WS_SYSMENU
WS_CHILDWINDOW       EQU	WS_CHILD
WS_TILED             EQU	WS_OVERLAPPED
WS_ICONIC            EQU	WS_MINIMIZE
WS_SIZEBOX           EQU	WS_THICKFRAME
WS_TILEDWINDOW       EQU	WS_OVERLAPPEDWINDOW
;WS_CAPTION           EQU	WS_BORDER | WS_DLGFRAME
WS_MODAL             EQU	WS_CAPTION | WS_SYSMENU | WS_VISIBLE
WS_MODELESS          EQU	WS_CAPTION | WS_SYSMENU | WS_VISIBLE
WS_CONTROL           EQU	WS_CHILD | WS_VISIBLE

WS_EX_NONE           EQU	00000000h
WS_EX_DLGMODALFRAME  EQU	000000001h
WS_EX_NOPARENTNOTIFY EQU	000000004h
WS_EX_TOPMOST        EQU	000000008h
WS_EX_ACCEPTFILES    EQU	000000010h
WS_EX_TRANSPARENT    EQU	000000020h
WS_EX_MDICHILD       EQU	000000040h
WS_EX_TOOLWINDOW     EQU	000000080h
WS_EX_WINDOWEDGE     EQU	000000100h
WS_EX_CLIENTEDGE     EQU	000000200h
WS_EX_CONTEXTHELP    EQU	000000400h

WS_EX_RIGHT          EQU	000001000h
WS_EX_LEFT           EQU	000000000h
WS_EX_RTLREADING     EQU	000002000h
WS_EX_LTRREADING     EQU	000000000h
WS_EX_LEFTSCROLLBAR  EQU	000004000h
WS_EX_RIGHTSCROLLBAR EQU	000000000h

WS_EX_CONTROLPARENT  EQU	000010000h
WS_EX_STATICEDGE     EQU	000020000h
WS_EX_APPWINDOW      EQU	000040000h

WS_EX_OVERLAPPEDWINDOW EQU	WS_OVERLAPPEDWINDOW | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE
WS_EX_PALETTEWINDOW  EQU	WS_EX_WINDOWEDGE  |  WS_EX_TOOLWINDOW | WS_EX_TOPMOST

SC_SIZE              EQU	0F000h
SC_MOVE              EQU	0F010h
SC_MINIMIZE          EQU	0F020h
SC_MAXIMIZE          EQU	0F030h
SC_NEXTWINDOW        EQU	0F040h
SC_PREVWINDOW        EQU	0F050h
SC_CLOSE             EQU	0F060h
SC_VSCROLL           EQU	0F070h
SC_HSCROLL           EQU	0F080h
SC_MOUSEMENU         EQU	0F090h
SC_KEYMENU           EQU	0F100h
SC_ARRANGE           EQU	0F110h
SC_RESTORE           EQU	0F120h
SC_TASKLIST          EQU	0F130h
SC_SCREENSAVE        EQU	0F140h
SC_HOTKEY            EQU	0F150h


;------------------------------------------------------------------------------

; =============
; dialog styles
; =============

DS_ABSALIGN          EQU	0001h
DS_SYSMODAL          EQU	0002h
DS_3DLOOK            EQU	0004h
DS_FIXEDSYS          EQU	0008h
DS_NOFAILCREATE      EQU	0010h
DS_LOCALEDIT         EQU	0020h
DS_SETFONT           EQU	0040h
DS_MODALFRAME        EQU	0080h
DS_NOIDLEMSG         EQU	0100h
DS_SETFOREGROUND     EQU	0200h
DS_CONTROL           EQU	0400h
DS_CENTER            EQU	0800h
DS_CENTERMOUSE       EQU	1000h
DS_CONTEXTHELP       EQU	2000h
DS_WINDOWSUI         EQU	8000h

DS_MODAL             EQU	DS_ABSALIGN | DS_MODALFRAME
DS_MODELESS          EQU	DS_ABSALIGN


;------------------------------------------------------------------------------

; =====================
; static control styles
; =====================

SS_LEFT              EQU	000000000h
SS_CENTER            EQU	000000001h
SS_RIGHT             EQU	000000002h
SS_ICON              EQU	000000003h
SS_BLACKRECT         EQU	000000004h
SS_GRAYRECT          EQU	000000005h
SS_WHITERECT         EQU	000000006h
SS_BLACKFRAME        EQU	000000007h
SS_GRAYFRAME         EQU	000000008h
SS_WHITEFRAME        EQU	000000009h
SS_USERITEM          EQU	00000000Ah
SS_SIMPLE            EQU	00000000Bh
SS_LEFTNOWORDWRAP    EQU	00000000Ch
SS_BITMAP            EQU	00000000Eh

SS_OWNERDRAW         EQU	00000000Dh
SS_ENHMETAFILE       EQU	00000000Fh
SS_ETCHEDHORZ        EQU	000000010h
SS_ETCHEDVERT        EQU	000000011h
SS_ETCHEDFRAME       EQU	000000012h
SS_TYPEMASK          EQU	00000001Fh

SS_NOPREFIX          EQU	000000080h
SS_NOTIFY            EQU	000000100h
SS_CENTERIMAGE       EQU	000000200h
SS_RIGHTJUST         EQU	000000400h
SS_REALSIZEIMAGE     EQU	000000800h
SS_SUNKEN            EQU	000001000h


;------------------------------------------------------------------------------

; =====================
; button control styles
; =====================

BS_PUSHBUTTON        EQU	000000000h
BS_DEFPUSHBUTTON     EQU	000000001h
BS_CHECKBOX          EQU	000000002h
BS_AUTOCHECKBOX      EQU	000000003h
BS_RADIOBUTTON       EQU	000000004h
BS_3STATE            EQU	000000005h
BS_AUTO3STATE        EQU	000000006h
BS_GROUPBOX          EQU	000000007h
BS_USERBUTTON        EQU	000000008h
BS_AUTORADIOBUTTON   EQU	000000009h
BS_OWNERDRAW         EQU	00000000Bh
BS_LEFTTEXT          EQU	000000020h
BS_TEXT              EQU	000000000h
BS_ICON              EQU	000000040h
BS_BITMAP            EQU	000000080h
BS_LEFT              EQU	000000100h
BS_RIGHT             EQU	000000200h
BS_CENTER            EQU	000000300h
BS_TOP               EQU	000000400h
BS_BOTTOM            EQU	000000800h
BS_VCENTER           EQU	000000C00h
BS_PUSHLIKE          EQU	000001000h
BS_MULTILINE         EQU	000002000h
BS_NOTIFY            EQU	000004000h
BS_FLAT              EQU	000008000h

BS_RIGHTBUTTON       EQU	BS_LEFTTEXT




;------------------------------------------------------------------------------

; ===================
; edit control styles
; ===================

ES_LEFT              EQU	000000000h
ES_CENTER            EQU	000000001h
ES_RIGHT             EQU	000000002h
ES_MULTILINE         EQU	000000004h
ES_UPPERCASE         EQU	000000008h
ES_LOWERCASE         EQU	000000010h
ES_PASSWORD          EQU	000000020h
ES_AUTOVSCROLL       EQU	000000040h
ES_AUTOHSCROLL       EQU	000000080h
ES_NOHIDESEL         EQU	000000100h
ES_OEMCONVERT        EQU	000000400h
ES_READONLY          EQU	000000800h
ES_WANTRETURN        EQU	000001000h
ES_NUMBER            EQU	02000h

ES_DEFAULT           EQU	ES_MULTILINE | ES_AUTOHSCROLL

;------------------------------------------------------------------------------

; =================
; scroll bar styles
; =================

SBS_HORZ             EQU	00000h
SBS_VERT             EQU	00001h
SBS_TOPALIGN         EQU	00002h
SBS_LEFTALIGN        EQU	00002h
SBS_BOTTOMALIGN      EQU	00004h
SBS_RIGHTALIGN       EQU	00004h
SBS_SIZEBOXTOPLEFTALIGN EQU	00002h
SBS_SIZEBOXBOTTOMRIGHTALIGN EQU	00004h
SBS_SIZEBOX          EQU	00008h
SBS_SIZEGRIP         EQU	00010h

;------------------------------------------------------------------------------

; ==============
; listbox styles
; ==============

LBS_NOTIFY           EQU	00001h
LBS_SORT             EQU	00002h
LBS_NOREDRAW         EQU	00004h
LBS_MULTIPLESEL      EQU	00008h
LBS_OWNERDRAWFIXED   EQU	00010h
LBS_OWNERDRAWVARIABLE EQU	00020h
LBS_HASSTRINGS       EQU	00040h
LBS_USETABSTOPS      EQU	00080h
LBS_NOINTEGRALHEIGHT EQU	00100h
LBS_MULTICOLUMN      EQU	00200h
LBS_WANTKEYBOARDINPUT EQU	00400h
LBS_EXTENDEDSEL      EQU	00800h
LBS_DISABLENOSCROLL  EQU	01000h
LBS_NODATA           EQU	02000h
LBS_NOSEL            EQU	04000h
LBS_STANDARD         EQU	(LBS_NOTIFY  |  LBS_SORT  |  WS_VSCROLL  |  WS_BORDER)

;------------------------------------------------------------------------------

; ================
; combo box styles
; ================

CBS_SIMPLE           EQU	00001h
CBS_DROPDOWN         EQU	00002h
CBS_DROPDOWNLIST     EQU	00003h
CBS_OWNERDRAWFIXED   EQU	00010h
CBS_OWNERDRAWVARIABLE EQU	00020h
CBS_AUTOHSCROLL      EQU	00040h
CBS_OEMCONVERT       EQU	00080h
CBS_SORT             EQU	00100h
CBS_HASSTRINGS       EQU	00200h
CBS_NOINTEGRALHEIGHT EQU	00400h
CBS_DISABLENOSCROLL  EQU	00800h
CBS_UPPERCASE        EQU	02000h
CBS_LOWERCASE        EQU	04000h

; operation messages sent to DLGINIT

;WM_USER              EQU	00400h
;LB_ADDSTRING         EQU	(WM_USER+1)
;CB_ADDSTRING         EQU	(WM_USER+3)


HDS_HORZ             EQU	000000000h
HDS_BUTTONS          EQU	000000002h
HDS_HIDDEN           EQU	000000008h

TTS_ALWAYSTIP        EQU	001h
TTS_NOPREFIX         EQU	002h

SBARS_SIZEGRIP       EQU	00100h

TBS_AUTOTICKS        EQU	00001h
TBS_VERT             EQU	00002h
TBS_HORZ             EQU	00000h
TBS_TOP              EQU	00004h
TBS_BOTTOM           EQU	00000h
TBS_LEFT             EQU	00004h
TBS_RIGHT            EQU	00000h
TBS_BOTH             EQU	00008h
TBS_NOTICKS          EQU	00010h
TBS_ENABLESELRANGE   EQU	00020h
TBS_FIXEDLENGTH      EQU	00040h
TBS_NOTHUMB          EQU	00080h

UDS_WRAP             EQU	00001h
UDS_SETBUDDYINT      EQU	00002h
UDS_ALIGNRIGHT       EQU	00004h
UDS_ALIGNLEFT        EQU	00008h
UDS_AUTOBUDDY        EQU	00010h
UDS_ARROWKEYS        EQU	00020h
UDS_HORZ             EQU	00040h
UDS_NOTHOUSANDS      EQU	00080h

;------------------------------------------------------------------------------

; ======================
; Common Control Styles
; ======================

CCS_TOP              EQU	000000001h
CCS_NOMOVEY          EQU	000000002h
CCS_BOTTOM           EQU	000000003h
CCS_NORESIZE         EQU	000000004h
CCS_NOPARENTALIGN    EQU	000000008h
CCS_NOHILITE         EQU	000000010h
CCS_ADJUSTABLE       EQU	000000020h
CCS_NODIVIDER        EQU	000000040h

;------------------------------------------------------------------------------

; ================
; list view styles
; ================

LVS_ICON             EQU	00000h
LVS_REPORT           EQU	00001h
LVS_SMALLICON        EQU	00002h
LVS_LIST             EQU	00003h
LVS_TYPEMASK         EQU	00003h

LVS_SINGLESEL        EQU	00004h
LVS_SHOWSELALWAYS    EQU	00008h
LVS_SORTASCENDING    EQU	00010h
LVS_SORTDESCENDING   EQU	00020h
LVS_SHAREIMAGELISTS  EQU	00040h
LVS_NOLABELWRAP      EQU	00080h
LVS_AUTOARRANGE      EQU	00100h
LVS_EDITLABELS       EQU	00200h

LVS_TYPESTYLEMASK    EQU	0000FC00h

LVS_ALIGNTOP         EQU	00000h
LVS_OWNERDRAWFIXED   EQU	00400h
LVS_ALIGNLEFT        EQU	00800h
LVS_ALIGNMASK        EQU	00c00h

LVS_NOSCROLL         EQU	02000h
LVS_NOCOLUMNHEADER   EQU	04000h
LVS_NOSORTHEADER     EQU	08000h

;------------------------------------------------------------------------------

; ================
; tree view styles
; ================

TVS_HASBUTTONS       EQU	00001h
TVS_HASLINES         EQU	00002h
TVS_LINESATROOT      EQU	00004h
TVS_EDITLABELS       EQU	00008h
TVS_DISABLEDRAGDROP  EQU	00010h
TVS_SHOWSELALWAYS    EQU	00020h

TCS_FORCEICONLEFT    EQU	00010h
TCS_FORCELABELLEFT   EQU	00020h
TCS_SHAREIMAGELISTS  EQU	00040h
TCS_TABS             EQU	00000h
TCS_BUTTONS          EQU	00100h
TCS_SINGLELINE       EQU	00000h
TCS_MULTILINE        EQU	00200h
TCS_RIGHTJUSTIFY     EQU	00000h
TCS_FIXEDWIDTH       EQU	00400h
TCS_RAGGEDRIGHT      EQU	00800h
TCS_FOCUSONBUTTONDOWN EQU	01000h
TCS_OWNERDRAWFIXED   EQU	02000h
TCS_TOOLTIPS         EQU	04000h
TCS_FOCUSNEVER       EQU	08000h

ACS_CENTER           EQU	00001h
ACS_TRANSPARENT      EQU	00002h
ACS_AUTOPLAY         EQU	00004h

; ===================
; dialog command id's
; ===================

IDOK                 EQU	1
IDCANCEL             EQU	2
IDABORT              EQU	3
IDRETRY              EQU	4
IDIGNORE             EQU	5
IDYES                EQU	6
IDNO                 EQU	7
IDCLOSE              EQU	8
IDHELP               EQU	9

IDC_STATIC           EQU	(-1)



;------------------------------------------------------------------------------

; ==============================
;  Predefined cursor & icon IDs
; ==============================


IDH_NO_HELP          EQU	28440
IDH_MISSING_CONTEXT  EQU	28441
IDH_GENERIC_HELP_BUTTON EQU	28442
IDH_OK               EQU	28443
IDH_CANCEL           EQU	28444
IDH_HELP             EQU	28445

;IDC_ARROW            EQU	32512
;IDC_IBEAM            EQU	32513
;IDC_WAIT             EQU	32514
;IDC_CROSS            EQU	32515
;IDC_UPARROW          EQU	32516
;IDC_SIZE             EQU	32640
;IDC_ICON             EQU	32641
;IDC_SIZENWSE         EQU	32642
;IDC_SIZENESW         EQU	32643
;IDC_SIZEWE           EQU	32644
;IDC_SIZENS           EQU	32645

;IDI_APPLICATION      EQU	32512
;IDI_HAND             EQU	32513
;IDI_QUESTION         EQU	32514
;IDI_EXCLAMATION      EQU	32515
;IDI_ASTERISK         EQU	32516
; background modes
; ================

TRANSPARENT          EQU	1
OPAQUE               EQU	2
BKMODE_LAST          EQU  2

; toolbar view bitmaps
; ====================

VIEW_LARGEICONS      EQU	0
VIEW_SMALLICONS      EQU	1
VIEW_LIST            EQU	2
VIEW_DETAILS         EQU	3
VIEW_SORTNAME        EQU	4
VIEW_SORTSIZE        EQU	5
VIEW_SORTDATE        EQU	6
VIEW_SORTTYPE        EQU	7
VIEW_PARENTFOLDER    EQU	8
VIEW_NETCONNECT      EQU	9
VIEW_NETDISCONNECT   EQU	10
VIEW_NEWFOLDER       EQU  11

; =====================
; ShowWindow() commands
; =====================

SW_HIDE              EQU	0
SW_SHOWNORMAL        EQU	1
SW_NORMAL            EQU	1
SW_SHOWMINIMIZED     EQU	2
SW_SHOWMAXIMIZED     EQU	3
SW_MAXIMIZE          EQU	3
SW_SHOWNOACTIVATE    EQU	4
SW_SHOW              EQU	5
SW_MINIMIZE          EQU	6
SW_SHOWMINNOACTIVE   EQU	7
SW_SHOWNA            EQU	8
SW_RESTORE           EQU	9
SW_SHOWDEFAULT       EQU	10
SW_MAX               EQU	10

;------------------------------------------------------------------------------

; ====================
; SetWindowPos() flags
; ====================

SWP_NOSIZE           EQU	0001h
SWP_NOMOVE           EQU	0002h
SWP_NOZORDER         EQU	0004h
SWP_NOREDRAW         EQU	0008h
SWP_NOACTIVATE       EQU	0010h
SWP_FRAMECHANGED     EQU	0020h
SWP_SHOWWINDOW       EQU	0040h
SWP_HIDEWINDOW       EQU	0080h
SWP_NOCOPYBITS       EQU	0100h
SWP_NOOWNERZORDER    EQU	0200h
SWP_NOSENDCHANGING   EQU	0400h
SWP_DEFERERASE       EQU	2000h
SWP_ASYNCWINDOWPOS   EQU	4000h

SWP_DRAWFRAME        EQU	SWP_FRAMECHANGED
SWP_NOREPOSITION     EQU	SWP_NOOWNERZORDER

; toolbar standard bitmaps
; ========================

STD_CUT              EQU	0
STD_COPY             EQU	1
STD_PASTE            EQU	2
STD_UNDO             EQU	3
STD_REDOW            EQU	4
STD_DELETE           EQU	5
STD_FILENEW          EQU	6
STD_FILEOPEN         EQU	7
STD_FILESAVE         EQU	8
STD_PRINTPRE         EQU	9
STD_PROPERTIES       EQU	10
STD_HELP             EQU	11
STD_FIND             EQU	12
STD_REPLACE          EQU	13
STD_PRINT            EQU  14
; status bar types
; ================

SBT_DEFAULT          EQU	0000h
SBT_NOBORDERS        EQU	0100h
SBT_POPOUT           EQU	0200h
SBT_RTLREADING       EQU	0400h
SBT_OWNERDRAW        EQU  1000h

; PRINTDLG definitions.
; =====================

PD_ALLPAGES          EQU	00000000h
PD_SELECTION         EQU	00000001h
PD_PAGENUMS          EQU	00000002h
PD_NOSELECTION       EQU	00000004h
PD_NOPAGENUMS        EQU	00000008h
PD_COLLATE           EQU	00000010h
PD_PRINTTOFILE       EQU	00000020h
PD_PRINTSETUP        EQU	00000040h
PD_NOWARNING         EQU	00000080h
PD_RETURNDC          EQU	00000100h
PD_RETURNIC          EQU	00000200h
PD_RETURNDEFAULT     EQU	00000400h
PD_SHOWHELP          EQU	00000800h
PD_ENABLEPRINTHOOK   EQU	00001000h
PD_ENABLESETUPHOOK   EQU	00002000h
PD_ENABLEPRINTTEMPLATE EQU	00004000h
PD_ENABLESETUPTEMPLATE EQU	00008000h
PD_ENABLEPRINTTEMPLATEHANDLE EQU	00010000h
PD_ENABLESETUPTEMPLATEHANDLE EQU	00020000h
PD_USEDEVMODECOPIES  EQU	00040000h
PD_USEDEVMODECOPIESANDCOLLATE EQU	00040000h
PD_DISABLEPRINTTOFILE EQU	00080000h
PD_HIDEPRINTTOFILE   EQU	00100000h
PD_NONETWORKBUTTON   EQU	00200000h

; toolbar bitmap id's
; ===================

IDB_STD_SMALL_COLOR  EQU	0
IDB_STD_LARGE_COLOR  EQU	1
IDB_VIEW_SMALL_COLOR EQU	4
IDB_VIEW_LARGE_COLOR EQU	5

HINST_COMMCTRL       EQU	-1

;------------------------------------------------------------------------------

; ====================
; standard cursor id's
; ====================

IDC_ARROW            EQU	32512
IDC_IBEAM            EQU	32513
IDC_WAIT             EQU	32514
IDC_CROSS            EQU	32515
IDC_UPARROW          EQU	32516
IDC_SIZE             EQU	32640      ;obsolete, use IDC_SIZEALL
IDC_ICON             EQU	32641      ;obsolete, use IDC_ARROW
IDC_SIZENWSE         EQU	32642
IDC_SIZENESW         EQU	32643
IDC_SIZEWE           EQU	32644
IDC_SIZENS           EQU	32645
IDC_SIZEALL          EQU	32646
IDC_NO               EQU	32648
IDC_APPSTARTING      EQU	32650
IDC_HELP             EQU	32651

;------------------------------------------------------------------------------

; ==================
; standard icon id's
; ==================

IDI_APPLICATION      EQU	32512
IDI_HAND             EQU	32513
IDI_QUESTION         EQU	32514
IDI_EXCLAMATION      EQU	32515
IDI_ASTERISK         EQU	32516
IDI_WINLOGO          EQU	32517

;------------------------------------------------------------------------------
; font weights
; ============

FW_DONTCARE          EQU	000
FW_THIN              EQU	100
FW_EXTRALIGHT        EQU	200
FW_LIGHT             EQU	300
FW_NORMAL            EQU	400
FW_MEDIUM            EQU	500
FW_SEMIBOLD          EQU	600
FW_BOLD              EQU	700
FW_EXTRABOLD         EQU	800
FW_HEAVY             EQU	900
;
FW_ULTRALIGHT        EQU	FW_EXTRALIGHT
FW_REGULAR           EQU	FW_NORMAL
FW_DEMIBOLD          EQU	FW_SEMIBOLD
FW_ULTRABOLD         EQU	FW_EXTRABOLD
FW_BLACK             EQU	FW_HEAVY

; font families
; =============

FF_DONTCARE          EQU	0000h
FF_ROMAN             EQU	0010h
FF_SWISS             EQU	0020h
FF_MODERN            EQU	0030h
FF_SCRIPT            EQU	0040h
FF_DECORATIVE        EQU  0050h


STRUC DIALOGATTRIBUTES
   .Palette:             resd	1	; DWORD
   .TextBox:             resd	1	; DWORD
ENDSTRUC

;------------------------------------------------------------------------------

STRUC DIALOGPALETTE  
   .DlgText:             resd	1	; COLORREF
   .DlgBk:               resd	1	; COLORREF
   .StaticText:          resd	1	; COLORREF
   .StaticBk:            resd	1	; COLORREF
   .TextBoxText:         resd	1	; COLORREF
   .TextBoxBk:           resd	1	; COLORREF
   .EditText:            resd	1	; COLORREF
   .EditBk:              resd	1	; COLORREF
   .ListBoxText:         resd	1	; COLORREF
   .ListBoxBk:           resd	1	; COLORREF
ENDSTRUC

;------------------------------------------------------------------------------

STRUC DIALOGRECORD   
   .hWnd:                resd	1	; HWND
   .fModeless:           resd	1	; BOOL
   .Attributes:          resd	1	; DWORD
   .Data:                resd	1	; DWORD
   .hDlgBrush:           resd	1	; HBRUSH
   .hStaticBrush:        resd	1	; HBRUSH
   .hTextBoxBrush:       resd	1	; HBRUSH
   .hEditBrush:          resd	1	; HBRUSH
   .hListBoxBrush:       resd	1	; HBRUSH
ENDSTRUC


STRUC PRINTDLG         
   .lStructSize:         resd	1	; DWORD
   .hwndOwner:           resd	1	; HWND
   .hDevMode:            resd	1	; HANDLE
   .hDevNames:           resd	1	; HANDLE
   .hDC:                 resd	1	; HDC
   .Flags:               resd	1	; DWORD
   .nFromPage:           resd	1	; WORD
   .nToPage:             resd	1	; WORD
   .nMinPage:            resd	1	; WORD
   .nMaxPage:            resd	1	; WORD
   .nCopies:             resd	1	; WORD
   .hInstance:           resd	1	; HINSTANCE
   .lCustData:           resd	1	; DWORD
   .lpfnPrintHook:       resd	1	; DWORD
   .lpfnSetupHook:       resd	1	; DWORD
   .lpPrintTemplateName: resd	1	; LPCTSTR
   .lpSetupTemplateName: resd	1	; LPCTSTR
   .hPrintTemplate:      resd	1	; HANDLE
   .hSetupTemplate:      resd	1	; HANDLE
ENDSTRUC



;------------------------------------------------------------------------------

STRUC PAINTSTRUCT    
   .hdc:                 resd	1	; HDC
   .fErase:              resd	1	; BOOL
   .leftPaint:           resd	1	; LONGINT
   .topPaint:            resd	1	; LONGINT
   .rightPaint:          resd	1	; LONGINT
   .bottomPaint:         resd	1	; LONGINT
   .fRestore:            resd	1	; BOOL
   .fIncUpdate:          resd	1	; BOOL
   .rgbReserved          resb    32 	; BYTE
ENDSTRUC

;------------------------------------------------------------------------------

STRUC RECT           
   .left:                resd	1	; LONGINT
   .top:                 resd	1	; LONGINT
   .right:               resd	1	; LONGINT
   .bottom:              resd	1	; LONGINT
ENDSTRUC

%define RECTL 	RECT
STRUC TBADDBITMAP    
   .hInst:               resd	1	; HINSTANCE
   .nID:                 resd	1	; UINT
ENDSTRUC

;------------------------------------------------------------------------------

STRUC TBBUTTON       
   .iBitmap:             resd	1	; INTEGER
   .idCommand:           resd	1	; INTEGER
   .fsState              resb   1       ; button state flags
   .fsStyle              resb   1       ; button style
   .bReserved:           resd	1	; WORD
   .dwData:              resd	1	; DWORD
   .iString:             resd	1	; INTEGER
ENDSTRUC

;------------------------------------------------------------------------------

STRUC TEXTMETRIC     
   .tmHeight:            resd	1	; LONGINT
   .tmAscent:            resd	1	; LONGINT
   .tmDescent:           resd	1	; LONGINT
   .tmInternalLeading:   resd	1	; LONGINT
   .tmExternalLeading:   resd	1	; LONGINT
   .tmAveCharWidth:      resd	1	; LONGINT
   .tmMaxCharWidth:      resd	1	; LONGINT
   .tmWeight:            resd	1	; LONGINT
   .tmOverhang:          resd	1	; LONGINT
   .tmDigitizedAspectX:  resd	1	; LONGINT
   .tmDigitizedAspectY:  resd	1	; LONGINT
   .tmFirstChar:         resb 1          ;first font character value
   .tmLastChar:          resb 1          ;last font character value
   .tmDefaultChar:       resb 1          ;default substitution character
   .tmBreakChar:         resb 1          ;word break character
   .tmItalic:            resb 1          ;italic font
   .tmUnderlined:        resb 1          ;underline font
   .tmStruckOut:         resb 1          ;strikeout font
   .tmPitchAndFamily:    resb 1          ;font pitch/family
   .tmCharSet:           resb 1          ;font character set

ENDSTRUC

;------------------------------------------------------------------------------

STRUC TOOLTIPTEXT    
   .hdr:                 resd   1       ; NMHDR structure
   .lpszText:            resd	1	; LPTSTR
   .szText:              resb   80      ; Tooltip text
   .hInst:               resd	1	; HINSTANCE
   .uFlags:              resd	1	; UINT
ENDSTRUC

;------------------------------------------------------------------------------

STRUC WNDCLASSEX
    .cbSize:          resd  1
    .style:           resd  1
    .lpfnWndProc:     resd  1
    .cbClsExtra:      resd  1
    .cbWndExtra:      resd  1
    .hInstance:       resd  1
    .hIcon:           resd  1
    .hCursor:         resd  1
    .hbrBackground:   resd  1
    .lpszMenuName:    resd  1
    .lpszClassName:   resd  1
    .hIconSm:         resd  1
ENDSTRUC
