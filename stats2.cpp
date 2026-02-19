#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int *array, int size);
double stddev(int *array, int size);

int main(){
    // Format all floating-point output to show 2 decimals
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Get input filename from user
    string filename("");
    cout << "Enter filename: ";
    cin >> filename;

    // Open the file for reading
    ifstream inputFile;
    inputFile.open(filename);

    // If file couldn't be opened, print error message and exit
    if (inputFile.fail()){
        cerr << "Cannot open " << filename << endl;
        exit(1);
    }

    // First pass through the file and count how many integers it contains
    int counter(0), temp;
    while (inputFile >> temp){
        counter++;
    }
    inputFile.close();

    // Only continue if the file contains at least one integer
    if (counter > 0){

        // Create a dynamic array big enough to hold all the integers
        int* dynarr = new int[counter];

        // Re-open the file for the second pass-through to actually read in the integers
        // If file couldn't be opened, print error message and exit
        inputFile.open(filename);
        if (inputFile.fail()){
            cerr << "Cannot open " << filename << endl;
            exit(1);
        }

        // Read exactly 'counter' number of integers into dynarr
        // Then close the file
        for (int i = 0; i < counter; i++){
            inputFile >> dynarr[i];
        }
        inputFile.close();
    
        // Sort the array so median() works correctly
        bubbleSort(dynarr, counter);
        
         // Print a summary of the statistics of the file
        cout << "Here are some statistics:\n";
        cout << setw(9) << "N: " << counter << endl;
        cout << setw(9) << "Average: " << average(dynarr, counter) << endl;
        cout << setw(9) << "Median: " << median(dynarr, counter) << endl;
        cout << setw(9) << "StdDev: " << stddev(dynarr, counter) << endl;

        // Free allocated memory
        delete [] dynarr;
        dynarr = nullptr;
    }

    // If counter == 0, program prints nothing beyond user prompts and exits normally.
    return 0;
}

// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
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

// Pre-Condition: It takes in a dynamic int array and its size
// Post-conditon: Returns the average of all the elements in the dynamic array.
double average(int *array, int size){
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }

    return (sum / size);
}

// Pre-Condition: It takes in a dynamic int array and its size
// Post-condition: Returns the median of all the elements in the dynamic array
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

// Pre-Condition: It takes in a dynamic int array and its size
// Post-condition; Returns the standard deviation of the elements in the dynamic array.
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
