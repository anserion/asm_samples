PROG= for_table.exe
OBJS= for_table.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
for_table.obj: 
	$(ASM) $(FLAGS) for_table.asm