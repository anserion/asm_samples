PROG= win_1.exe
OBJS= win_1.obj
LIBS= 
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
	strip $(PROG)
#==========================================================
win_1.obj: 
	$(ASM) $(FLAGS) win_1.asm