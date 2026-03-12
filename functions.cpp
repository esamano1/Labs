// file: functions.cpp for newanagrams

// Pre-condition:
//     Takes no arguments
// Post-condition:
//     Initializes the class AString's string variable to an empty string
AString::AString(){
    StringValue = "";
}

// Pre-condition:
//     Takes a string (str) as an argument
// Post-condition:
//     Initializes StringValue to the value of str
AString::AString(string str){
    StringValue = str;
}

// Pre-condition:
//     Takes no arguments
// Post-condition:
//     Returns the string value of AString's StringValue variable 
string AString::getStringValue(){
    return StringValue;
}

// Pre-condition:
//     Takes no arguments
// Post-condition:
//     Removes non-alphabetical characters from the member variable StringValue and makes all alphabetical characters lowercase
void AString::cleanUp(){
    string temp = "";

    for (unsigned int i = 0; i < StringValue.length(); i++){
        if ((StringValue[i] >= 'A') && (StringValue[i] <= 'Z')){
            temp += StringValue[i] + 32;
        }
        else if ((StringValue[i] >= 'a') && (StringValue[i] <= 'z')){
            temp += StringValue[i];
        }
    }

    StringValue = temp;
    return;
}

// Pre-condition:
//     Takes in an integer array of size 26 (letterCount[])
// Post-condition:
//     The function counts the frequency of each letter in the member variable StringValue and put that frequency in the corresponding index in letterCount[]
void AString::countLetters(int letterCount[]){
    for (unsigned int i = 0; i < StringValue.length(); i++){
        for (int j = 0; j < 26; j++){
            // need to delete the condition for capital letters.
            if ((StringValue[i] == j + 65) || (StringValue[i] == j + 97)){
                letterCount[j] += 1;
            }
        }
    }
    return;
}

// Pre-condition:
//     Takes no arguments
// Post-condition:
//     Prompts the user for any string and sets StringValue to the string the user inputted
void AString::getAString(){
    cout << "Enter string value: ";
    getline(cin, StringValue);
    return;
}

// Pre-condition:
//     Takes two integer arrays of size 26
// Post-condition:
//     If the values of the arrays aren't equal then the function returns false, otherwise it returns true
bool compareCounts(int a[], int b[]){
    for (int i = 0; i < 26; i++){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}
