#!/bin/bash


#os := $(shell uname -s)
#arch := $(shell uname -m)

ifeq ($(shell uname -m),x86_64)
        arch =x86_64-linux-gnu
else
        arch =i386-linux-gnu
endif

prefix = /usr/local

INSTDIR = $(prefix)/bin

LIBDIR = $(prefix)/lib

LIB_FOLDER = lib

CC = gcc

CFLAGS = -g -Wall -std=c99

LIBFLAGS = -g -shared -fPIC

OBJECTS = electrotest.o

C_FILES = src/electrotest.c

PROG = electrotest

HEADERS = include/libresistance.h include/libpower.h include/libcomponent.h

$(PROG): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(PROG) -L. -lresistance -lpower -lcomponent

$(OBJECTS):  $(C_FILES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(C_FILES) -L.  -lresistance -lpower -lcomponent

clean:
	rm -rf *.o $(PROG)  
	
distclean: clean 
  
all: program


install: $(PROG)
		install -D $(PROG) \
			$(DESTDIR)$(prefix)/bin/electrotest

uninstall:
		rm -f $(DESTDIR)$(prefix)/bin/electrotest
	

.PHONY: all install clean distclean uninstall
