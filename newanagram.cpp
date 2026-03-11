/* 
 * NEWANAGRAM.CPP by Ziad Matni (c) 2024
 * For use in CS16 labs 
 *
 * DO NOT CHANGE ANYTHING ALREADY IN THIS PROGRAM!
 * Students should fill in the places where it says *** MISSING CODE HERE! ***
 */
#include <iostream>
#include <string>
using namespace std;

#include "headers.h"
#include "functions.cpp"

int main() {
    // 1. Declare 2 objects of AString,
    //      construct as asked to (see PDF document), 
    //      get the string values using class --member function-- getStringValue(),
    //      print the string values
    AString sentence1, sentence2("nothing");
    cout << "Two objects declared with values: ";
    cout << sentence1.getStringValue() << " and ";
    cout << sentence2.getStringValue() << endl;


    // 2. Get user inputs using class --member function-- getAString()
    //      and clean up the strings using class --member function-- cleanUp()

    // *** MISSING CODE HERE! *** //


    // 3. Set up 2 arrays and initialize to all zeros
    //      and count letters in the strings using class --member function-- countLetters()

    int ca1[26] = {0}, ca2[26]={0};
    // *** MISSING CODE HERE! *** //


    // 4. Use external function compareCounts to decide
    //      if the 2 strings are anagrams of each other or not

    // *** MISSING CODE HERE! *** //

    if (badCount) {
        // *** MISSING CODE HERE! *** //
    } else {
        // *** MISSING CODE HERE! *** //
    }

    return 0;
}
