main:
	g++  main5.cpp -o test
	./test

funkcijos:
	g++ -c print.cpp Studentas.cpp

clean:
	del print.o Studentas.o test