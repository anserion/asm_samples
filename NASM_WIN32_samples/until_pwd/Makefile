PROG= until_pwd.exe
OBJS= until_pwd.obj
LIBS=
FLAGS= -f win32
LINK= gcc
ASM= nasm

all: $(OBJS)
	$(LINK) -o $(PROG) $(OBJS) $(LIBS)
	del $(OBJS)
#==========================================================
until_pwd.obj: 
	$(ASM) $(FLAGS) until_pwd.asm