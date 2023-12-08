PROG= win_btns.exe
OBJS= win_btns.obj
LIBS= 
FLAGS= -f win32
LINK= mingw32-gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
	strip $(PROG)
#==========================================================
win_btns.obj: 
	$(ASM) $(FLAGS) win_btns.asm