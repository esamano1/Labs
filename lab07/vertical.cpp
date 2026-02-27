/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
#include <iostream>
using namespace std;

// printV prints the digits of a nonnegative integer one per line,
// from most significant digit to least significant digit.
void printV(long int num);

int main() {

    // 1. Get user input
    long int userInput;
    cout << "Enter integer: ";
    cin >> userInput;

    // 2. Check input and pass it on to printV()
    //    This program only accepts nonnegative integers.
    //    If valid, pass it to printV() to display vertically.
    if (userInput < 0){
        cout << "Input must be a positive integer.\n";
    }
    else{
        printV(userInput);
    }

    return 0;
}

// Pre-conditions:
//    num is a nonnegative integer
// Post-conditions:
//    Prints each digit of num on its own line, in left-to-right order.
void printV(long int num){

    // Base case: single-digit number
    if (num < 10){
        cout << num << endl;
        return; 
    }

    // Recursive call: recursively print all digits except the last one
    printV(num/10);
    cout << num % 10 << endl;
}
