all: vertical palindrome selectionSort

vertical: vertical.cpp
	g++ vertical.cpp -o vertical -Wall -std=c++17

palindrome: palindrome.cpp pfunctions.cpp
	g++ -c palindrome.cpp -o palindrome.o
	g++ -c pfunctions.cpp -o pfunctions.o
	g++ palindrome.o pfunctions.o -o palindrome -Wall -std=c++17

selectionSort: selectionSort.cpp sfunctions.cpp
	g++ -c selectionSort.cpp -o selectionSort.o
	g++ -c sfunctions.cpp -o sfunctions.o
	g++ selectionSort.o palindrome.o -o selectionSort -Wall -std=c++17

clean:
	rm vertical
	rm palindrome
	rm selectionSort
