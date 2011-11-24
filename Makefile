# Copyright (c) 2011 Javier Escalada Gómez
# All rights reserved.

CC = gcc
CXX = g++
CFLAGS = -std=c99
CFLAGS += -g -Wall -Wreturn-type -O0 -DDEBUG
CXXFLAGS = -g -Wall -Wreturn-type -O0 -DDEBUG
LDFLAGS =

PYTHON = /usr/bin/python

all: encrypted_strings.def hello_c hello_cpp

hello_c: encrypted_strings.o

hello_cpp: encrypted_strings.o

encrypted_strings.def: strings.list
	$(PYTHON) string_cypher.py

clean:
	-@$(RM) hello_c
	-@$(RM) hello_cpp
	-@$(RM) *.o
	-@$(RM) -r hello_c.dSYM
	-@$(RM) -r hello_cpp.dSYM
	-@$(RM) encrypted_strings.def

distclean: clean