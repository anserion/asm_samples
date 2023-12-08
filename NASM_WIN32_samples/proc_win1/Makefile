PROG= proc_win1.exe
OBJS= proc_win1.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
proc_win1.obj: 
	$(ASM) $(FLAGS) proc_win1.asm