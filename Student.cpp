#include "Student.h"
#include <sstream> // for ostringstream

// Initializes the perm number and name variables of the student class
Student::Student(int p, 
		      string lName, 
		      string fName) {
    perm = p;
    lastName = lName;
    firstAndMiddleNames = fName; 
}

// Returns the perm number of the student
int Student::getPerm() { 
  return perm;
}

// Returns The student's last name
string Student::getLastName() { 
  return lastName;
}

// Returns the first and middle names of the student
string Student::getFirstAndMiddleNames() { 
  return firstAndMiddleNames;
}

// Returns the full name of the student
string Student::getFullName() { 
  return firstAndMiddleNames + " " + lastName;
}

// THIS MEMBER FUNCTION IS DEFINED FOR YOU ALREADY:
// DO NOT CHANGE IT
string Student::toString()  { 
  // e.g. [12345,Smith,Malory Logan]
  ostringstream oss;
  
  oss << "[" 
      << getPerm() << ","
      << getLastName() << ","
      << getFirstAndMiddleNames() << "]";
  return oss.str();
} 

