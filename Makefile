fizzbuzz: main.o Decoder.o 
	g++ main.o Decoder.o -o fizzbuzz 
main.o : main.cpp
	g++ -c main.cpp
Decoder.o : Decoder.cpp
	g++ -c Decoder.cpp
clean:
	rm *.o fizzBuzz.exe