compile: src/main.cpp
	g++ -g -Wall -Wextra src/main.cpp src/Reader.cpp src/Buzon.cpp -o main

.PHONY: lint
lint:
	cpplint src/main.cpp

.PHONY: memcheck
memcheck: main
	valgrind --tool=memcheck --leak-check=full ./main

.PHONY: clean
clean:
	rm -f main *.txt