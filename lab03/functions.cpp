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
#include "constants.h"
#include "headers.h"

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
void print_array(int arr[], int asize){
    for (int i = 0; i < asize; i++){
        cout << arr[i];
        if (i < asize-1){
            cout << ", ";
        }
    }
    cout << endl;
}


int maxArray(int arr[], int asize){
    int max = arr[0];
    for (int i = 1; i < asize; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}


int minArray(int arr[], int asize){
    int min = arr[0];
    for (int i = 1; i < asize; i++){
        if (arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}


int sumArray(int arr[], int asize){
    int sum = 0;
    for (int i = 0; i < asize; i++){
        sum += arr[i];
    }

    return sum;
}


void evensArray(int arr[], int asize){
    cout << "Evens: ";
    for (int i = 0; i < asize; i++){
        if (arr[i] % 2 == 0){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
}


void primesArray(int arr[], int asize){
    bool prime;
    cout << "Primes: ";
    for (int i = 0; i < asize; i++){
        prime = true;
        if (((arr[i]%2 == 0) && (arr[i] > 2))|| (arr[i] <= 1)){
            prime = false;
        }
        else{
            for (int j = 3; j < arr[i]/2; j += 2){
                if ( arr[i]%j == 0){
                    prime = false;
                }   
            }
        }
        if (prime == true){
            cout << arr[i] << ", ";
        }
    }
    cout << "end" << endl;
}


int SeqSearch(int arr[], int array_size, int target){
    for (int i = 0; i < array_size; i++){
        if (arr[i] == target){
            return i;
        }
    }

    return -1;
}


void AllSearches(int array[], int array_size){
    cout << "Searches:\n";
    for (int i = 0; i < NSEARCHES; i++){
        cout << "Looking for " << SEARCHES[i] << ". ";
        int index = SeqSearch(array, array_size, SEARCHES[i]);
        switch (index){
            case -1:
                cout << "Not Found!\n";
                break;
            default:
                cout << "Found at index: " << index << endl;
                break;
        }
    }
}
