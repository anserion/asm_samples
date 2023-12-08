PROG= output2.exe
OBJS= output2.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
output2.obj: 
	$(ASM) $(FLAGS) output2.asm