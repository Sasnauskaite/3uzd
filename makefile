main:
	g++  main5.cpp -o test
	./test

funkcijos:
	g++ -c func5.cpp print.cpp

clean:
	del func5.o print.o test