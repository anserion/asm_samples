PROG= win_gl.exe
OBJS= win_gl.obj DrawScene.obj readbmp.obj
LIBS= -lgdi32 -lopengl32 -lglu32 -mwindows
FLAGS= -f win32 
LINK= mingw32-gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
	strip $(PROG)
#==========================================================
win_gl.obj: 
	$(ASM) $(FLAGS) win_gl.asm
DrawScene.obj: 
	$(ASM) $(FLAGS) DrawScene.asm
readbmp.obj:
	$(ASM) $(FLAGS) readbmp.asm