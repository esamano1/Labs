// file: r_headers.h
// Do NOT change this file at all!

const string OUTPUTFILE = "Results.txt";

void NameSort(UndergradStudents array[], int size);

void InitializeStructures(UndergradStudents us[], int &size);

void WriteResults(ofstream &outf, UndergradStudents us[], int size);
