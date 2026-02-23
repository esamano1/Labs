/* Main function for palindrome.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"

int main() {

    // 1. Get a string from the user (see examples given)
    string userInput;
    cout << "Enter sentence:\n";
    getline(cin, userInput);

    // 2. Clean up the string using the required function
    cleanUp(userInput);

    // 3. Check to see if string is a palindrome
    bool isPalin;
    isPalin = isPalindrome(userInput);

    // 4. Print out message accordingly (see examples given)
    if (isPalin){
        cout << "It is a palindrome.\n";
    }
    else{
        cout << "It is not a palindrome.\n";
    }

    return 0;
}

