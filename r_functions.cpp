// file: r_functions.cpp
// Eduardo Samano
// Define the functions, per the list in r_headers.h

void NameSort(UndergradStudents array[], int size){
    for (int i = size; i >= 1; i--){
        for (int j = 1, j < i; j++){
            if (array[j-1].lastName[0] > array[j].lastName[0]){
                UndergradStudents temp = array[j-1];
                array[j-1] = array [j];
                array[j] = temp;
            }
        }
    }
}

void InitializeStructures(UndergradStudents us[], int &size){
    cout << "STUDENTS RECORDS:\n";
    string quit;
    size = 0;
    for (size; size < 9; size++){

        cout << "Student 0" << size + 1 << ":Enter first name (or x to quit): ";
        getline(cin, quit);
        if ( (quit == "X") || (quit == "x") ){
            return;
        }
        us[size].firstName = quit;

        cout << "Student 0" << size + 1 << ":Enter last name: ";
        getline(cin, us[size].lastName);
        cout << "Student 0" << size + 1 << ":Enter major: ";
        cin >> us[size].major;

        cout << "Student 0" << size + 1 << ":Enter GPA Year 1: ";
        cin >> us[size].1stGPA;
        cout << "Student 0" << size + 1 << ":Enter GPA Year 2: ";
        cin >> us[size].2ndGPA;
        cout << "Student 0" << size + 1 << ":Enter GPA Year 3: ";
        cin >> us[size].3rdGPA;
        cout << "Student 0" << size + 1 << ":Enter GPA Year 4: ";
        cin >> us[size].4thGPA;

        us[size].studentID = size + 1;
    }

    for (size; size < 20; size++){

        cout << "Student " << size + 1 << ":Enter first name (or x to quit): ";
        getline(cin, quit);
        if ( (quit == "X") || (quit == "x") ){
            return;
        }
        us[size].firstName = quit;

        cout << "Student " << size + 1 << ":Enter last name: ";
        getline(cin, us[size].lastName);
        cout << "Student " << size + 1 << ":Enter major: ";
        cin >> us[size].major;

        cout << "Student " << size + 1 << ":Enter GPA Year 1: ";
        cin >> us[size].1stGPA;
        cout << "Student " << size + 1 << ":Enter GPA Year 2: ";
        cin >> us[size].2ndGPA;
        cout << "Student " << size + 1 << ":Enter GPA Year 3: ";
        cin >> us[size].3rdGPA;
        cout << "Student " << size + 1 << ":Enter GPA Year 4: ";
        cin >> us[size].4thGPA;

        us[size].studentID = size + 1;
    }

}

void WriteResults(ofstream &outf, UndergradStudents us[], int size){
    float avgGPA;
    NameSort(us, size);
    outf.open(OUTPUTFILE);
    outf << fixed << showpoint;
    outf << setprecision(2);
    outf << "These are the results sorted by last name:\n";
    for (int i = 0; i < size; i++){
        avgGPA = (us[i].1stGPA + us[i].2ndGPA + us[i].3rdGPA + us[i].4thGPA)/4;
        outf << "ID# " << us[i].studentID 
            << ": " << us[i].lastName 
            << ": " << us[i].firstName 
            << ": " << us[i].major 
            << ": " << avgGPA << endl;
    }
    outf.close()
}
