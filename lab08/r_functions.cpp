// file: r_functions.cpp
// Eduardo Samano
// Define the functions, per the list in r_headers.h

// Pre-conditions:
//     array is an UndergradStudents array with 'size' elements
//     size is greater than or equal to 0
// Post-conditions:
//     Reorders array in-place so that records are sorted by last name (roughly)
void NameSort(UndergradStudents array[], int size){

    // Bubble sort: After each outer for loop, the element with the last name that 
    //             begins with a letter last in the alphabet, bubbles up to the end of the array.
    for (int i = size; i >= 1; i--){
        for (int j = 1; j < i; j++){

            // Compare first letter of last names and swap if out of order
            if (array[j-1].lastName[0] > array[j].lastName[0]){
                UndergradStudents temp = array[j-1];
                array[j-1] = array [j];
                array[j] = temp;
            }
        }
    }
}


// Pre-conditions:
//     us[] is an UndergradSrudents array with a capacity of at least 20 elements
//     size is an int whos value will become the size of us[]
// Post-conditions:
//     Prompts the user to enter up to 20 student records
//     Stops early if user enters 'x' or 'X' for the first name
//     Updates 'size' to reflect how many student records were entered
void InitializeStructures(UndergradStudents us[], int &size){
    cout << "STUDENTS RECORDS:\n";
    string quit, studentNum;

    // Fill us[] until 20 students have been enetered or user quits
    for (size = 0; size < 20; size++){
        
        // Determines which student label to use depending on which student# we are currently on
        if (size < 9){
            studentNum = "Student 0";
        }
        else{
            studentNum = "Student ";
        }

        // Prompt for first name and allow user to quit by entering x or X
        cout << studentNum << size + 1 << ":Enter first name (or x to quit): ";
        getline(cin, quit);
        if ( (quit == "X") || (quit == "x") ){
            return;
        }
        us[size].firstName = quit;

        // Read in last name as a full line
        cout << studentNum << size + 1 << ":Enter last name: ";
        getline(cin, us[size].lastName);

        // Read in major of the current student
        cout << studentNum << size + 1 << ":Enter major: ";
        cin >> us[size].major;

        // Read in GPAs for each year for the current student
        cout << studentNum << size + 1 << ":Enter GPA Year 1: ";
        cin >> us[size].GPA1st;
        cout << studentNum << size + 1 << ":Enter GPA Year 2: ";
        cin >> us[size].GPA2nd;
        cout << studentNum << size + 1 << ":Enter GPA Year 3: ";
        cin >> us[size].GPA3rd;
        cout << studentNum << size + 1 << ":Enter GPA Year 4: ";
        cin >> us[size].GPA4th;

        // So that the next getline() works correctly.
        cin.ignore();

        // Assign the student ID as the number of accumulated iterations
        us[size].studentID = size + 1;
        cout << endl;
    } 
}


// Pre-conditions:
//     outf is an ofstream object (not open yet)
//     us contains 'size' filled student records
//     size is grater than or equal to 0
//     OUTPUTFILE is defined as the output filename in the other program
// Post-conditions:
//     Sorts the student array by using NameSort()
//     Writes one line per student to OUTPUTFILE
//     Each output line includes ID, last name, first name, major, and 4-year average GPA
//     Closes the output file
void WriteResults(ofstream &outf, UndergradStudents us[], int size){
    float avgGPA;

    // Sort the records before writing them into the file
    NameSort(us, size);

    // Open the output file and set formatting for the GPA output
    outf.open(OUTPUTFILE);
    outf << fixed << showpoint;
    outf << setprecision(2);

    outf << "These are the results sorted by last name:\n";

    // Iterate over the elements present in us[] and write each student's summary on one line
    for (int i = 0; i < size; i++){
        
        // Compute 4-year average GPA
        avgGPA = (us[i].GPA1st + us[i].GPA2nd + us[i].GPA3rd + us[i].GPA4th)/4;
        outf << "ID# " << us[i].studentID 
            << ": " << us[i].lastName 
            << ": " << us[i].firstName 
            << ": " << us[i].major 
            << ": " << avgGPA << endl;
    }
    
    outf.close();
}
