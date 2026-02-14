#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int *array, int size);
double stddev(int *array, int size);

int main(){
    cout << fixed << showpoint;
    cout << setprecision(2);

    string filename("");
    cout << "Enter filename: ";
    cin >> filename;

    ifstream inputFile;
    inputFile.open(filename);

    
    //I could open the file, run a counter, then close the file. Make a dynamic int array of size counter and then open up the file again and read in the elements
    //open file
    //while not at end of filer:
    //  counter++
    //close file
    //dynamic int array[counter]
    //for (i = 0; i < counter; i++):
    //  file >> array[i]
    //close file
    

    
    //open file
    //counter = 0
    //while file >> next:
    //  counter++
    //  if counter % 2 == 0
    //      int* arr1 = new int[counter]
    //      for (int i = 0; i < counter; i++)
    //          
    //  if counter % 2 == 1
    //      int* arr2 = new int[counter]
    //      for (f)

    cout << "Here are some statistics:\n";
    cout << setw(9) << "N: " << /* x */ << endl;
    cout << setw(9) << "Average: " << average(grades, num_of_grades) << endl;
    cout << setw(9) << "Median: " << median(grades, num_of_grades) << endl;
    cout << setw(9) << "StdDev: " << stddev(grades, num_of_grades) << endl;

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
