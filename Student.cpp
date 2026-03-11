#include "Student.h"
#include <sstream> // for ostringstream

Student::Student(int p, 
		      string lName, 
		      string fName) {
  // THIS EMPTY CONSTRUCTOR IS A STUB
  // DELETE THESE COMMENTS AND REPLACE WITH APPROPRIATE CODE
  // REMEMBER: PURPOSE OF A CONSTRUCTOR IS TO INITIALIZE 
  // ALL DATA MEMBERS WITH REASONABLE VALUES  
}

// THE NEXT 4 MEMBER FUNCTIONS NEED TO BE DEFINED BY THE STUDENT
//      AND ARE, IN THE MEANTIME, DEFINED AS STUBS:
int Student::getPerm() { 
  return -999;
}

string Student::getLastName() { 
  return "stub";
}

string Student::getFirstAndMiddleNames() { 
  return "stub";
}

string Student::getFullName() { 
  return "stub";
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

