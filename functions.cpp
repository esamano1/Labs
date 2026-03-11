// file: functions.cpp for newanagrams

// Define all member functions for class AString
//    as well as all other functions that need definition
AString::AString(){
    StringValue = "";
}

AString::AString(string str){
    StringValue = str;
}

string AString::getStringValue(){
    return StringValue;
}

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

void AString::getAString(){
    cout << "Enter string value: ";
    getline(cin, StringValue);
    return;
}

bool compareCounts(int a[], int b[]){
    for (int i = 0; i < 26; i++){
        if (a[i] != b[i]){
            return false;
        }
    }
    return true;
}
