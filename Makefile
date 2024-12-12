compile:
	mkdir -p bin
	g++ -std=c++20 -Wall src/*.cpp -o bin/chess
run:
	./bin/chess
test:
	make compile && make run
