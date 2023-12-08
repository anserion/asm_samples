PROG= proc_cube.exe
OBJS= proc_cube.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
proc_cube.obj: 
	$(ASM) $(FLAGS) proc_cube.asm