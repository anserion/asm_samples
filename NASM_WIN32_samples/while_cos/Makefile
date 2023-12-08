PROG= while_cos.exe
OBJS= while_cos.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
while_cos.obj: 
	$(ASM) $(FLAGS) while_cos.asm