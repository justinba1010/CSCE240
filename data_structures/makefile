CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

compile:
	g++ -std=c++11 -Wall -o main main.cc;

struct: struct.cc
	$(LINK) struct struct.cc
	./struct

clean:
	rm main$

ignore_errors:
	g++ -std=c++11 -o main main.cc;

.PHONY: struct
