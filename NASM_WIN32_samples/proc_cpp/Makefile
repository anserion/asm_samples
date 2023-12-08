#Makefile
PROG= prog.exe
OBJS= prog1.obj funcs.obj
LIBS= 
FLAGS= -f win32
LINK= gcc
ASM= nasm
GCC= gcc

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del *.obj
#==========================================================
funcs.obj: 
	$(ASM) $(FLAGS) funcs.asm
prog1.obj: 
	$(GCC) -c -o prog1.obj prog1.cpp
