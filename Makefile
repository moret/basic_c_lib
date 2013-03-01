all: test

test: dirs
	@echo 'Target $@'
	gcc tests/check_my_lib.c src/my_lib.c -lcheck -o bin/check_test_suite
	bin/check_test_suite

lib: dirs
	@echo 'Target $@'
	gcc src/my_lib.c -shared -c -o bin/libmy_lib.so

dirs:
	mkdir -p bin/

clean:
	rm -rf bin/
