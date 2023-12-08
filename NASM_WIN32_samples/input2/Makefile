PROG= input2.exe
OBJS= input2.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
input2.obj: 
	$(ASM) $(FLAGS) input2.asm