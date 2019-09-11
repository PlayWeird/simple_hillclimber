all: eval eval1 my_eval

eval: main.cpp eval.o
	g++ -o solver -static main.cpp eval.o

eval1: main.cpp eval1.o
	g++ -o solver1 -static main.cpp eval1.o

my_eval: main.cpp my_eval.o
	g++ -o my_solver -static main.cpp my_eval.o

my_eval.o: my_eval.cpp
	g++ -c my_eval.cpp

clean:
	rm -f solver solver1 my_solver my_eval.o