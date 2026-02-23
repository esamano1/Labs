// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments
int getFileSize(ifstream& inf, string fname){
    int size(0), temp;
    inf.open(fname);
    while (inf >> temp){
        size++;
    }
    inf.close();
    return size;
}

void getArray(ifstream& in, string fname, int arr[], int size){
    in.open(fname);
    for (int i = 0; i < size; i++){
        in >> arr[i];
    }
    in.close();
}

void sort(bool desc, int a[], int number_used, int index){
    if (number_used == 0){
        return;
    }

    swap_values(a[index], a[find_index_of_swap(desc, a, index, number_used)]);
    sort(desc, a, number_used - 1, index + 1);
}

int find_index_of_swap(bool desc, int a[], int start_index, int number_used){
    int swap_index = start_index;
     if (desc){
        int max = a[start_index];
        for (int i = start_index; i < start_index + number_used; i++){
            if (a[i] > max){
                max = a[i];
                swap_index = i;
            }
        }

     }
     else{
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

void swap_values(int& v1, int& v2){
    int temp = v1;
    v1 = v2;
    v2 = temp;
}
