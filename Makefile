compile:
	mkdir -p bin
	g++ -Wall src/*.cpp -o bin/chess
run:
	./bin/chess
test:
	make compile && make run