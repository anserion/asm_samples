PROG= complex.exe
OBJS= complex.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
complex.obj: 
	$(ASM) $(FLAGS) complex.asm