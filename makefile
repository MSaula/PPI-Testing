SHELL:=/bin/bash
CC=g++
CFLAGS=-I -Wall -Wextra 
DEPS = person.h catch.hpp

#Color aleatori because yes.
all:
	@clear
	@echo -n -e "\e[3$$(( $$RANDOM * 6 / 32767 + 1))mCompilant exerici...\n\033[0m"
	 #$(CC) person.c $(DEPS) $(CFLAGS) -o test
	@echo -n -e "\e[3$$(( $$RANDOM * 6 / 32767 + 1))mFet!\n\033[0m"
	
clean:
	@rm person.o test