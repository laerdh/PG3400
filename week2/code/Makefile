CC=gcc
AS=as
CFLAGS=-g -O0
CSFLAGS=-g -O0 -S
PFLAGS=-E

1: 1.o
	$(CC) -o 1 $(CFLAGS) 1.o
2: 2.o
	$(CC) -o 2 $(CFLAGS) 2.o
3: 3.o
	$(CC) -o 3 $(CFLAGS) 3.o
clean:
	rm -f *.o 1 2 3 1_preproc.c 1_compiled_assembly.s 1_binary_code.o
preprocess: 1.c
	$(CC) -o 1_preproc.c $(PFLAGS) 1.c
compile: 1_preproc.c
	$(CC) -o 1_compiled_assembly.s $(CSFLAGS) 1_preproc.c
assemble: 1_compiled.s
	$(AS) 1_compiled_assembly.s -o 1_binary_code.o
