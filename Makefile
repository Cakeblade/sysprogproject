CC = gcc
AR = ar
MAINSRC = main.c
SRC = mstr.c
LIBNAME = mstr
TARGET = libtest

all : OBJECT STALIB SHALIB $(TARGET)_STALIB $(TARGET)_SHALIB

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

clean:
	rm -rf $(TARGET)_static $(TARGET)_shared lib$(LIBNAME)* *.o lib
