PROG= if_ab.exe
OBJS= if_ab.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
if_ab.obj: 
	$(ASM) $(FLAGS) if_ab.asm