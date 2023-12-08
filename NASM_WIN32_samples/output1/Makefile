PROG= output1.exe
OBJS= output1.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#	strip $(PROG)
#==========================================================
output1.obj: 
	$(ASM) $(FLAGS) output1.asm
