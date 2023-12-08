PROG= arith.exe
OBJS= arith.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
arith.obj: 
	$(ASM) $(FLAGS) arith.asm