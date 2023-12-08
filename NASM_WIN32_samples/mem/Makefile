PROG= mem.exe
OBJS= mem.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
mem.obj: 
	$(ASM) $(FLAGS) mem.asm