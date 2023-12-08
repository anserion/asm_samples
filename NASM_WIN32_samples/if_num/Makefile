PROG= if_num.exe
OBJS= if_num.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
if_num.obj: 
	$(ASM) $(FLAGS) if_num.asm