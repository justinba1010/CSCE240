CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

compile:
	g++ -std=c++11 -Wall -o main main.cc;

stackmain: stackmain.cc
	$(LINK) stackmain stackmain.cc
	./stackmain

clean:
	rm main$

ignore_errors:
	g++ -std=c++11 -o main main.cc;

.PHONY: struct stackmain
