CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test : test_get_num_grades test_get_grades test_get_max_grade_id \
        test_get_max_grade test_get_grade
	./test_get_num_grades
	./test_get_grades
	./test_get_grade
	./test_get_max_grade_id
	./test_get_max_grade

test_get_num_grades : test_get_num_grades.cc parse_scores.o
	$(LINK) $@ $^

test_get_grades : test_get_grades.cc parse_scores.o
	$(LINK) $@ $^

test_get_grade : test_get_grade.cc parse_scores.o
	$(LINK) $@ $^

test_get_max_grade_id : test_get_max_grade_id.cc parse_scores.o
	$(LINK) $@ $^

test_get_max_grade : test_get_max_grade.cc parse_scores.o
	$(LINK) $@ $^

parse_scores.o : parse_scores.cc parse_scores.h
	$(COMPILE) $<

clean:
	rm -f parse_scores.o test_get_num_grades test_get_grades \
            test_get_max_grade_id test_get_max_grade test_get_grade
zip:
	zip hw2 parse_scores.cc parse_score.h makefile test*.cc
