CC = g++-8  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


build: makemake
	./a.out

makemake:
	$(CC) bad_dyn_arr.cc
	
test: pointers
	./pointers.o

pointers : pointers.cc pointers.o
	$(LINK) $@ $^

# Utilities

lint:
	# First get the header file right, then the cc file.
	python ../../cpplint.py gradebook.h && python ../../cpplint.py gradebook.cc

zip:
	zip hw4 gradebook.h gradebook.cc init.sh makefile test_*.cc

clean:
	rm -f gradebook.o test?
