PROG= for_stepen.exe
OBJS= for_stepen.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
for_stepen.obj: 
	$(ASM) $(FLAGS) for_stepen.asm