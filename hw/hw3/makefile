CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test_gradebook : test_gradebook.o gradebook.o
	$(LINK) $@ $^

test_gradebook.o : test_gradebook.cc gradebook.o
	$(COMPILE) $<

gradebook.o : gradebook.cc gradebook.h
	$(COMPILE) $<

clean:
	rm -f gradebook.o test_gradebook.o test_gradebook

zip:
	zip hw3 gradebook.h gradebook.cc test_gradebook.cc makefile

.PHONY: test_gradebook

