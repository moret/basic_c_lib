all: test

test:
	@echo 'Target $@'
	rm -rf bin/
	mkdir bin/
	gcc tests/check_my_lib.c src/my_lib.c -lcheck -o bin/check_test_suite
	bin/check_test_suite
