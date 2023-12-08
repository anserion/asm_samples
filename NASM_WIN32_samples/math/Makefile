PROG= math.exe
OBJS= math.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
math.obj: 
	$(ASM) $(FLAGS) math.asm