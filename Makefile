compile:
	mkdir -p bin
	g++ -std=c++20 -Wall src/*.cpp -o bin/chess
run:
	./bin/chess
test:
	rm -rf ./bin/chess
	make compile
	clear
	./bin/chess

debug:
	rm -rf ./bin/chess
	g++ -g -std=c++20 -Wall src/*.cpp -o bin/chess
	clear