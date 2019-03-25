CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test : parse_scores
	python3 test_parse_scores.py

parse_scores : parse_scores.cc
	$(LINK) $@ $^ 

clean:
	@rm parse_scores

#to_linux:
	#bash ./linux.sh

zip:
	zip hw1 * -x parse_scores;
