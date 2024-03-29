compile: src/main.cpp
	g++ -std=c++17 -g -Wall -Wextra src/main.cpp src/Reader.cpp src/Buzon.cpp src/Semaforo.cpp -o main

.PHONY: lint
lint:
	cpplint src/main.cpp

.PHONY: memcheck
memcheck: main
	valgrind --tool=memcheck --leak-check=full ./main

.PHONY: clean
clean:
	rm -f main results/*.txt