// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// Pre-conditions:
//     inf is an ifstream object
//     fname is the name of a file containing integers
// Post-conditions:
//     Opens fname, counts how many integers are in the file, closes the file
//     Returns the number of integers found
int getFileSize(ifstream& inf, string fname){
    // Declare temp, and initialize size to 0
    int size(0), temp;

    // Open the file and count how many integers can be read
    inf.open(fname);
    while (inf >> temp){
        size++;
    }

    // Close file before returning
    inf.close();
    return size;
}

// Pre-conditions:
//     in is an ifstream object
//     fname is the name of a file containing 'size' number of integers
//     arr has capacity for of 'size'
// Post-conditions:
//     Opens fname, reads 'size' integers into arr[], closes the file
void getArray(ifstream& in, string fname, int arr[], int size){
    in.open(fname);
    for (int i = 0; i < size; i++){
        in >> arr[i];
    }
    in.close();
}

// Pre-conditions:
//     a is an array
//     number_used should be the size of the array
//     index should be 0
//     desc == true  -> sort in descending order
//     desc == false -> sort in ascending order
// Post-conditions:
//     Sorts the array recursively in descending or ascending order
void sort(bool desc, int a[], int number_used, int index){
    // Base case: no elements left to sort
    if (number_used == 0){
        return;
    }

    // Find the index of the value that should go at a[index]
    // then swap it into place
    swap_values(a[index], a[find_index_of_swap(desc, a, index, number_used)]);
    
    // Recursively sort the rest of the array
    sort(desc, a, number_used - 1, index + 1);
}

// Pre-conditions:
//     a is a an array
//     start_index is the first index in the array being searched
//     number_used is the number of elements after a[start_index]
//     desc determines search mode:
//       true  -> find index of maximum value
//       false -> find index of minimum value
// Post-conditions:
//     Returns the index of the max/min element in the range:
//       a[start_index] through a[start_index + number_used - 1]
int find_index_of_swap(bool desc, int a[], int start_index, int number_used){
    int swap_index = start_index;
     if (desc){
        // Descending sort: find index of the largest value in the current subarray
        int max = a[start_index];
        for (int i = start_index; i < start_index + number_used; i++){
            if (a[i] > max){
                max = a[i];
                swap_index = i;
            }
        }

     }
     else{
        // Ascending sort: find index of the smallest value in the current subarray
        int min = a[start_index];
        for (int i = start_index; i < start_index + number_used; i++){
            if (a[i] < min){
                min = a[i];
                swap_index = i;
            }
        }
     }

     return swap_index;
}

// Pre-conditions:
//     v1 and v2 are valid int references
// Post-conditions:
//     The values in v1 and v2 are exchanged
void swap_values(int& v1, int& v2){
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
