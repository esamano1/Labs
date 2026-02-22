/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;

// Declare printV() here
void printV(long int num);

int main() {

    // 1. Get user input
    long int userInput;
    cout << "Enter integer: ";
    cin >> userInput;

    // 2. Check input and pass it on to printV()
    if (userInput < 0){
        cout << "Input must be a positive integer.\n";
    }
    else{
        printV(userInput);
    }

    return 0;
}

// Define printV() here
void printV(long int num){
    if (num < 10){
        cout << num << endl;
        return; 
    }
    printV(num/10);
    cout << num % 10 << endl;
}
