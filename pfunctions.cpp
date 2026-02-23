// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments

bool isPalindrome(string s) {

    if (s.length() <= 1){
        return true;
    }
    
    // test for strings of length 2
    if (isPalindrome(s.substr(1, s.length() - 2)) && (s[0] == s[s.length() - 1])){
        return true;
    }
    else{
        return false;
    }
}

void cleanUp(string &s) {
    string temp = "";
    for (int i = 0; i < s.length(); i++){
        if ( (s[i] >= 'A') && (s[i] <= 'Z') ){
            temp += s[i] + 32;
        }
        else if ( (s[i] >= 'a') && (s[i] <= 'z') ){
            temp += s[i];
        }
    }
    s = temp;
    return;
}
