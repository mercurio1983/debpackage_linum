#!/bin/bash

prefix = /usr/local

INSTDIR = $(prefix)/bin

LIBDIR = $(prefix)/lib

CURRENT_DIR = $(shell pwd)

LIB_FOLDER = lib

#Kompilator
CC = gcc

CFLAGS = -g -Wall -std=c99

LIBFLAGS = -g -shared -fPIC

LIB_C_FILE3 = src/libcomponent.c


LIB_OBJECT3 = libcomponent.o

LIB_SO3 = libcomponent.so

$(LIB_SO3): $(LIB_OBJECT3)
	$(CC) $(LIBFLAGS) -o $(LIB_SO3) $(LIB_OBJECT3)

$(LIB_OBJECT3): $(LIB_C_FILE3)
	$(CC) -c -g -fPIC $(LIB_C_FILE3)

lib: $(LIB_SO3)

clean:
	rm -rf *.o *.so  

distclean: clean 
  
all: $(LIB_SO3) 


#Part1a: $(LIB_SO3) 
	#@if [ -d $(CURRENT_DIR)/$(LIB_FOLDER) ]; then \
	#mv $(LIB_SO3) $(CURRENT_DIR)/$(LIB_FOLDER);\
	#else \
	#mkdir $(LIB_FOLDER);\
	#mv $(LIB_SO3) $(CURRENT_DIR)/$(LIB_FOLDER);\
	#fi
	


# Om filen är en directory	
#Kopiera
#sätt exekverbara rättigheter till alla för programmet
#ta bort skriv rättigheter till andra och grupper för programmet

install: $(LIB_SO3)
		install -D $(LIB_SO3) \
			$(DESTDIR)$(prefix)/lib/libcomponent.so


 

#Part2a: 
		#@if [ -d $(LIBDIR) ];\
		#then\
		#cp $(CURRENT_DIR)/$(LIB_FOLDER)/$(LIB_SO3) $(DESTDIR)/$(LIBDIR);\
		#echo "Library installed in $(LIBDIR)" ;\
		#else\
		#echo "Sorry, the library folder $(LIBDIR) does not exist";\
		#fi



#Kontrollera om programmet finns
#ta bort den från directory /usr/bin
#Om inte ge utskrift att den har redan tagits bort
#Om inte så existerar inte directoryn
	
uninstall:
		rm -f $(DESTDIR)$(prefix)/lib/libcomponent.so

		#@if [ -e $(DESTDIR)/$(LIBDIR)/$(LIB_SO3) ];\
		#then\
		#rm $(DESTDIR)/$(LIBDIR)/$(LIB_SO3);\
		#echo "Library $(LIB_SO3) is removed from directory $(LIBDIR)";\
		#elif [ -d $(DESTDIR)/$(LIBDIR) ];\
		#then\
		#echo "Library $(LIB_SO3) already removed from $(LIBDIR)";\
		#else\
		#echo "Directory $(LIBDIR) does not exist";\
		#fi		

.PHONY: all install clean distclean uninstall
