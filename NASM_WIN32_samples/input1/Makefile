PROG= input1.exe
OBJS= input1.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
input1.obj: 
	$(ASM) $(FLAGS) input1.asm