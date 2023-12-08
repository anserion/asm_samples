PROG= win_timer.exe
OBJS= win_timer.obj DrawScene.obj readbmp.obj
LIBS= -lgdi32 -lopengl32 -lglu32 -mwindows
FLAGS= -f win32 
LINK= mingw32-gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
	strip -s $(PROG)
#==========================================================
win_timer.obj: 
	$(ASM) $(FLAGS) win_timer.asm
DrawScene.obj: 
	$(ASM) $(FLAGS) DrawScene.asm
readbmp.obj:
	$(ASM) $(FLAGS) readbmp.asm