#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int *array, int size);
double stddev(int *array, int size);

int main(){
    string filename("");
    cout << "Enter filename: ";
    cin >> filename;

    cout << "Here are some statistics:\n"

    return 0;
}

void bubbleSort(int *array, int size){
    int temp;
    for (int i = size-1; i >= 0; i--){
        for (int j = 1; j <= i; j++){
            if (array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }
}

double average(int *array, int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }

    return (sum / size);
}

double median(int *array, int size){
    if (size % 2 == 0){
        double sum = 0;
        sum = array[size/2 - 1] + array[size/2];
        return (sum / 2);
    }
    else{
        double value = array [size/2];
        return value;
    }
}

double stddev(int *array, int size){
    if (size == 1){
        return 0;
    }
    double avg(average(array, size)), sum(0), difference(0), root(0);
    for (int i = 0; i < size; i++){
        difference = array[i] - avg;
        sum += pow(difference, 2);
    }

    root = sum / (size - 1);
    return pow(root, .5);
}
