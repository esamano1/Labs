// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// Pre-conditions:
//     s is a string, preferably cleaned before-hand
// Post-conditions:
//     Returns true if s is a palindrome
//     Returns false otherwise
bool isPalindrome(string s) {

    // Base case: empty string or single character is a palindrome
    if (s.length() <= 1){
        return true;
    }
    
    // Recursive case: Check whether the inner substring is a palindrome AND
    //  if the first and last characters match
    if (isPalindrome(s.substr(1, s.length() - 2)) && (s[0] == s[s.length() - 1])){
        return true;
    }
    else{
        return false;
    }
}

// Pre-conditions:
//     s is a string passed in by reference so it can be modified
// Post-conditions:
//     s contains only lowercase letters a-z
//     all punctuation, digits, spaces, etc. are removed
void cleanUp(string &s) {
    // Initialize a an empty string to temporarily store only the lowercase letters in s
    string temp = "";

    // Copy only letters into temp, converting uppercase to lowercase
    for (int i = 0; i < s.length(); i++){
        if ( (s[i] >= 'A') && (s[i] <= 'Z') ){
            temp += s[i] + 32;
        }
        else if ( (s[i] >= 'a') && (s[i] <= 'z') ){
            temp += s[i];
        }
    }
    // replace original with cleaned version
    s = temp;
    return;
}
