PROG= proc_2.exe
OBJS= main.obj funcs.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del *.obj
#==========================================================
main.obj: 
	$(ASM) $(FLAGS) main.asm
funcs.obj: 
	$(ASM) $(FLAGS) funcs.asm