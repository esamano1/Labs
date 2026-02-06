#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main(){
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Declares variable that will be the size of grades later.
    int num_of_grades;

    // Prompts the user to input how many grades will be in the dynamic array.
    cout << "Enter number of grades: ";
    cin >> num_of_grades;

    // This if checks if the number the user inputted was less than 1. 
    // If it was then it outputs an error message.
    if (num_of_grades < 1){
        cerr << "Error!\n";
        exit(1);
    }

    // If the number of grades the user inputted was 1 or greater, then 
    // a dynamic int array of that size is declared. 
    int* grades = new int[num_of_grades];

    //The user is prompted to fill the dynamic int array with the grades of students.
    cout << "Enter grades (each on a new line):\n";
    for (int i = 0; i < num_of_grades; i++){
        cin >> grades[i];
    }

    // The dynamic int arrray is sorted first, and then the average, median, and
    // standard deviation of the dynamic int array are printed to the screen.
    bubbleSort(grades, num_of_grades);
    cout << "Here are some statistics:\n";
    cout << setw(9) << "Average: " << average(grades, num_of_grades) << endl;
    cout << setw(9) << "Median: " << median(grades, num_of_grades) << endl;
    cout << setw(9) << "StdDev: " << stddev(grades, num_of_grades) << endl;

    delete [] grades;

    return 0;
}

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

// Pre-Condition: It takes in a dynamic int array and its size
// Post-conditon: Returns the average of all the elements in the dynamic array.
double average(int *array, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += array[i];
    }
    return static_cast<double>(sum) / size;
}

// Pre-Condition: It takes in a dynamic int array and its size
// Post-condition: Returns the median of all the elements in the dynamic array
double median(int* array, int size){
    if (size % 2 == 0){
        int sum = 0;
        sum = array[size/2 - 1] + array[size/2];
        return static_cast<double>(sum) / 2;
    }
    else{
        double value = array[size/2];
        return value;
    }
}

// Pre-Condition: It takes in a dynamic int array and its size
// Post-condition; Returns the standard deviation of the elements in the dynamic array.
double stddev(int* array, int size){

    // if the size of dyn. int array is equal to 1, then the function returns a std of
    // 0 and this also prevents a division by zero toward the end of the function.
    if (size == 1){
        return 0;
    }
    double avg = average(array, size);
    double sum = 0;
    double difference = 0;
    double root = 0;
    for (int i = 0; i < size; i++){
        difference = array[i] - avg;
        sum += pow(difference, 2);
    }

    root = sum / (size - 1);
    return pow(root, .5);
}
