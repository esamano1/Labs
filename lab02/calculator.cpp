// Calculator.cpp
// By: Eduardo Samano
// Created on: 1/18/26

#include <iostream>
#include <cstdlib>
using namespace std;

//Usage: ./calculate int char int
//char can be one of 4 things: + - x or %
int main( int argc, char *argv[] )
{
    int int1, int2;
    // PART 1: Check to see if the number of arguments is correct
    //          Hint: use "if (argc ...)" to check this,
    //          use cerr to output any messages
    if (argc != 4){
        cerr << "Number of arguments is incorrect.\n";
        exit(1);
    }
    
    // Part 2: Convert arguments into integers (only those that need it!)
    //          Hint: this means using atoi()
    int1 = atoi(argv[1]);
    int2 = atoi(argv[3]);

    // Part 3: Check for illegal operations like divide by zero...
    //          use cerr to output any messages

    // Part 4: Do the appropriate calculations,
    //          outputs using both cout and cerr, etc...
    switch (argv[2][0]){//This switch compares the character of the second command-line
                        //argument, to see if it is +, -, *, or %.
        case '+'://if it is + then we perform addition on int1 & int2.
            cout << int1 + int2 << endl;
            break;
        case '-'://if it is - then we perform subtraction on int1 & int2.
            cout << int2 - int2 << endl;
            break;
        case '*'://if it is * then we perform multiplication on int1 & int2.
            cout << int1 * int2 << endl;
            break;
        case '%'://if it is % then we check if int2 is 0. If it is not then we perform modulo
                 //like normal.
            if (int2 == 0){
                cerr << "Cannot divide by zero." << endl;
                exit(1);
            } else {
                cout << int1 % int2 << endl;
            }
            break;
        default://otherwise, the second command-line argument is none of the four valid operators.
            cerr << "Bad operation choice.\n";
            exit(1);
            break;
    }
    return 0;
}
