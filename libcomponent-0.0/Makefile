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

LIB_C_FILE3 = src/libcomponent.c


LIB_OBJECT3 = libcomponent.o

LIB_SO3 = libcomponent.so.0.0.0

$(LIB_SO3): $(LIB_OBJECT3)
	$(CC) $(LIBFLAGS) -Wl,-soname=libcomponent.so.0 -o $(LIB_SO3) $(LIB_OBJECT3) 
	ln -s libcomponent.so.0.0.0 libcomponent.so.0
	ln -s libcomponent.so.0.0.0 libcomponent.so
	
$(LIB_OBJECT3): $(LIB_C_FILE3)
	$(CC) -c -g -fPIC $(LIB_C_FILE3)

lib: $(LIB_SO3)

clean:
	rm -rf *.o *.so libcomponent.so.0 libcomponent.so.0.0.0

distclean: clean 
  
all: $(LIB_SO3) 

install: $(LIB_SO3)
		install -D $(LIB_SO3) \
			$(DESTDIR)$(prefix)/lib/$(arch)/libcomponent.so.0.0.0
		ln -s libcomponent.so.0.0.0 $(DESTDIR)$(prefix)/lib/$(arch)/libcomponent.so.0

uninstall:
		rm -f $(DESTDIR)$(prefix)/lib/$(arch)/libcomponent.so.0.0.0 $(DESTDIR)$(prefix)/lib/$(arch)/libcomponent.so.0
	

.PHONY: all install clean distclean uninstall
