CC = g++
CFLAGS = -Wall -Wextra -std=c++11
LDLIBS =
P = llista
OBJ = main.o list.o person.o

TEST_MODULES = TESTS/person-test TESTS/list-test
OBJ_PERSON_TESTS = TESTS/person-test.o person.o
OBJ_LIST_TESTS = TESTS/list-test.o list.o person.o


### Compilation Targets ###
.PHONY: all
all: $(P)

$(P): $(OBJ)
	$(CC) $(OBJ) -o $(P) $(CFLAGS)

### Testing Targets ###
.PHONY: run-tests make-tests
run-tests:
	./TESTS/person-test
	./TESTS/list-test

make-tests: $(TEST_MODULES)

	# Test Modules
TESTS/person-test: $(OBJ_PERSON_TESTS)
	$(CC) $(OBJ_PERSON_TESTS) $(CFLAGS) $(LDLIBS) -o $@

TESTS/list-test: $(OBJ_LIST_TESTS)
	$(CC) $(OBJ_LIST_TESTS) $(CFLAGS) $(LDLIBS) -o $@


#Cleanning Targets
.PHONY: clean clean-tests
clean:
	rm $(OBJ) $(P)

clean-tests:
	rm $(OBJ_LIST_TESTS) $(OBJ_PERSON_TESTS) $(TEST_MODULES)
