CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test: init test1 test2 test3 test4 test5 test6
	./test1
	./test2
	./test3
	./test4
	./test5
	./test6

init:
	bash ./init.sh

test1 : test_operator_plus_grade.cc gradebook.o
	$(LINK) $@ $^

test2 : test_operator_plus_gradebook.cc gradebook.o
	$(LINK) $@ $^

test3 : test_operator_equal_to_gpa.cc gradebook.o
	$(LINK) $@ $^

test4 : test_operator_equal_to_gradebook.cc gradebook.o
	$(LINK) $@ $^

test5 : test_operator_less_than_gpa.cc gradebook.o
	$(LINK) $@ $^

test6 : test_operator_less_than_gradebook.cc gradebook.o
	$(LINK) $@ $^

gradebook.o : gradebook.cc gradebook.h
	$(COMPILE) $<

# Utilities

lint:
	# First get the header file right, then the cc file.
	python ../../cpplint.py gradebook.h && python ../../cpplint.py gradebook.cc

zip:
	zip hw4 gradebook.h gradebook.cc init.sh makefile test_*.cc

clean:
	rm -f gradebook.o test?
