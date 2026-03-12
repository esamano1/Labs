#include "Student.h"
#include <sstream> // for ostringstream

Student::Student(int p, 
		      string lName, 
		      string fName) {
    perm = p;
    lastName = lName;
    firstAndMiddleNames = fName;
  // THIS EMPTY CONSTRUCTOR IS A STUB
  // DELETE THESE COMMENTS AND REPLACE WITH APPROPRIATE CODE
  // REMEMBER: PURPOSE OF A CONSTRUCTOR IS TO INITIALIZE 
  // ALL DATA MEMBERS WITH REASONABLE VALUES  
}

// THE NEXT 4 MEMBER FUNCTIONS NEED TO BE DEFINED BY THE STUDENT
//      AND ARE, IN THE MEANTIME, DEFINED AS STUBS:
int Student::getPerm() { 
  return perm;
}

string Student::getLastName() { 
  return lastName;
}

string Student::getFirstAndMiddleNames() { 
  return firstAndMiddleNames;
}

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

