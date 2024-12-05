CC = gcc
AR = ar
MAINSRC = main.c
RUNSRC = runtime.c
LIBNAME = mstr
TARGET = libtest

all : OBJECT STALIB SHALIB $(TARGET)_STALIB $(TARGET)_SHALIB $(TARGET)_RUNTIME

OBJECT : mstr.c
	$(CC) -Og -c -fpic mstr.c

STALIB : mstr.o
	$(AR) -rc lib$(LIBNAME).a mstr.o

SHALIB : mstr.o
	export LD_LIBRARY_PATH=./
	$(CC) -shared -o lib$(LIBNAME).so mstr.o

$(TARGET)_STALIB : lib$(LIBNAME).a
	$(CC) -static $(MAINSRC) -L. -l$(LIBNAME) -o $(TARGET)_static

$(TARGET)_SHALIB : lib$(LIBNAME).so
	$(CC) $(MAINSRC) -L. -l$(LIBNAME) -o $(TARGET)_shared 

$(TARGET)_RUNTIME : lib$(LIBNAME).so
	$(CC) -rdynamic -o $(TARGET)_runtime $(RUNSRC) -ldl

clean:
	rm -rf $(TARGET)_* lib$(LIBNAME)* *.o
