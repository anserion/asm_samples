PROG= proc_ref.exe
OBJS= proc_ref.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
proc_ref.obj: 
	$(ASM) $(FLAGS) proc_ref.asm