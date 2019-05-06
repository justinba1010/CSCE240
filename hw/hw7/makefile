CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

INCLUDE =  -I inc  # add inc dir to include path
INCLUDE += -I src  # add src dir to include path
FLAGS += $(INCLUDE)

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

HW=hw7
USERNAME=jabaum

test_constructor : test_matrix_constructor.o
	$(LINK) $@ $^

test_get : test_matrix_get.o
	$(LINK) $@ $^

test_assign : test_matrix_assign.o
	$(LINK) $@ $^

test_mul_assign : test_matrix_mul_assign.o
	$(LINK) $@ $^

test_add : test_matrix_add.o
	$(LINK) $@ $^

test_matrix_constructor.o : src/test_matrix_constructor.cc \
                            inc/test_matrix.h src/matrix.cc inc/matrix.h
	$(COMPILE) $<

test_matrix_get.o : src/test_matrix_get.cc inc/test_matrix.h \
                    src/matrix.cc inc/matrix.h
	$(COMPILE) $<

test_matrix_assign.o : src/test_matrix_assign.cc inc/test_matrix.h \
                       src/matrix.cc inc/matrix.h
	$(COMPILE) $<

test_matrix_mul_assign.o : src/test_matrix_mul_assign.cc inc/test_matrix.h \
                           src/matrix.cc inc/matrix.h
	$(COMPILE) $<

test_matrix_add.o : src/test_matrix_add.cc inc/test_matrix.h \
                    src/matrix.cc inc/matrix.h
	$(COMPILE) $<


clean:
	rm -f *.o test_constructor test_get test_assign test_mul_assign test_add

test-all: test_constructor test_get test_assign test_mul_assign test_add
	./test_constructor
	./test_get
	./test_assign
	./test_mul_assign
	./test_add

zip:
	zip -r $(HW) inc src makefile

upload: zip
	echo "rm -rf $(HW); mkdir $(HW); exit" | ssh -p 222 $(USERNAME)@L-1D43-01.cse.sc.edu
	scp -P 222 $(HW).zip $(USERNAME)@L-1D43-01.cse.sc.edu:~/$(HW)/$(HW).zip
	echo "cd $(HW); unzip $(HW).zip; make test-all; make valgrind; exit" | ssh -p 222 $(USERNAME)@L-1D43-01.cse.sc.edu

valgrind:
	$(BASH) for file in test_*; do valgrind ./$$file; done