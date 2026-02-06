/*
/ Skeleton File for FUNCTIONS.CPP for CS16, UCSB
/ Copyright © 2026 by Ziad Matni. All rights reserved.
/
*/

// DO NOT MODIFY THESE NEXT 5 LINES - DO NOT ADD TO THEM
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// INCLUDE HEADER FILE(S) HERE:


// The following function is defined for you. ***Do not change it AT ALL.***
//
// Pre-Condition: takes in an ifstream object for input file, 
//              a string for an input filename, an integer array and its size
// Post-Condition: the array will be populated with all the numbers from the input file
void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}

// Add your 8 functions definitions below:

