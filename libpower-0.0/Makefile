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

LIB_C_FILE3 = src/libpower.c


LIB_OBJECT3 = libpower.o

LIB_SO2 = libpower.so.0.0.0

$(LIB_SO2): $(LIB_OBJECT3)
	$(CC) $(LIBFLAGS) -Wl,-soname=libpower.so.0 -o $(LIB_SO2) $(LIB_OBJECT3) 
	ln -s libpower.so.0.0.0 libpower.so.0
	ln -s libpower.so.0.0.0 libpower.so
	
$(LIB_OBJECT3): $(LIB_C_FILE3)
	$(CC) -c -g -fPIC $(LIB_C_FILE3)

lib: $(LIB_SO2)

clean:
	rm -rf *.o *.so libpower.so.0 libpower.so.0.0.0

distclean: clean 
  
all: $(LIB_SO2) 

install: $(LIB_SO2)
		install -D $(LIB_SO2) \
			$(DESTDIR)$(prefix)/lib/$(arch)/libpower.so.0.0.0
		ln -s libpower.so.0.0.0 $(DESTDIR)$(prefix)/lib/$(arch)/libpower.so.0

uninstall:
		rm -f $(DESTDIR)$(prefix)/lib/$(arch)/libpower.so.0.0.0 $(DESTDIR)$(prefix)/lib/$(arch)/libpower.so.0
	

.PHONY: all install clean distclean uninstall
