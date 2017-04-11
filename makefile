all: head ls cal true false env

head: head.o
	g++ -o head head.o

head.o: head.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c head.cpp

ls: ls.o
	g++ -o ls ls.o

ls.o: ls.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ls.cpp

cal: cal.o
	g++ -o cal cal.o

cal.o: cal.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c cal.cpp

true: true.o
	g++ -o true true.o

true.o: true.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c true.cpp

false: false.o
	g++ -o false false.o

false.o: false.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c false.cpp

env: env.o
	g++ -o env env.o

env.o: env.cpp
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c env.cpp

clean:
	rm -f head.o
	rm -f head
	rm -f ls.o
	rm -f ls
	rm -f cal.o
	rm -f cal
	rm -f true.o
	rm -f true
	rm -f false.o
	rm -f false
	rm -f env.o
	rm -f env
