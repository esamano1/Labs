/* records.cpp
 * For use in CS16, (c) 2024, Matni
 *
 * Do not change any code in this file.
 */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "structs.h"        // Needs completion
#include "headers.h"        // Do not change
#include "functions.cpp"    // Needs completion

int main() {
    UndergradStudents ObjArray[20];
    int ObjArraySize;
    ofstream outf;

    InitializeStructures(ObjArray, ObjArraySize);
    WriteResults(outf, ObjArray, ObjArraySize);
    
    return 0;
}
