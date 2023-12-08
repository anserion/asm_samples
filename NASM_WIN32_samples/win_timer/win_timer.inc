extern _GetModuleHandleA@4
extern _LoadIconA@8
extern _LoadCursorA@8
extern _LoadIconA@8
extern _RegisterClassExA@4
extern _CreateWindowExA@48
extern _ShowWindow@8
extern _UpdateWindow@4
extern _GetMessageA@16
extern _TranslateMessage@4
extern _DispatchMessageA@4
extern _DefWindowProcA@16 ;Обработчик сообщений по умолчанию
extern DrawScene  ;вызываем функцию рисования на полотне
extern _SetTimer@16
extern _memset   ;memset(&pfd,0,sizeof(pfd));
extern _GetDC@4
extern _ChoosePixelFormat@8
extern _SetPixelFormat@12  ;SetPixelFormat(hdc,nPixelFormat,&pfd);
extern _wglCreateContext@4
extern _wglMakeCurrent@8  ;wglMakeCurrent(hdc,hrc);
extern _glEnable@4
extern _glLightModelfv@8
extern _glLightfv@12
extern _glLightfv@12
extern _glLightfv@12
extern _glLightfv@12
extern _glLightfv@12
extern _glEnable@4
extern _glViewport@16 ;glViewport(0,0,windW,windH);
extern _glMatrixMode@4    ;glMatrixMode(GL_PROJECTION);
extern _glLoadIdentity@0  ;glLoadIdentity();
extern _gluPerspective@32 ;gluPerspective(60,1.5,1.0,1000);
extern _glMatrixMode@4   ;glMatrixMode(GL_MODELVIEW);
extern _glTranslatef@12
extern _glRotatef@16
extern _glRotatef@16
extern _glClearColor@16
extern LoadFromBMP
extern MakeTexture
extern _KillTimer@8
extern _wglMakeCurrent@8
extern _wglDeleteContext@4
extern _DeleteDC@4
extern _free
extern _free
extern _PostQuitMessage@4
