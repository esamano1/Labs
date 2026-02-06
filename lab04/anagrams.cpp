#include <iostream>
#include <string>
using namespace std;

void find_letters(int letters[26], string str);
// Pre-condition: Takes in an int array that is of size 26, as well as a string.
//
// Post-condition: Counts how many times a letter appears in string and puts that
// number in their corrresponding index in the array.

void are_anagrams(int letters1[26], int letters2[26]);
// Pre-condition: Takes two int arrays of size 26
//
// Post-condition: Compares each corresponding index of the two arrays and
// prints "The strings are not anagrams." if any of the corresponding indicies do 
// not have the same value or if both arrays are only zeros.
// Otherwise, the two arrays are non-zero arrays and hold the exact same 
// values and the function prints "The strings are anagrams."



int main()
{
    // Declaring strings and initializing integer arrays of size 26 to zeros.
    const unsigned int size = 26;
    string str1, str2;
    int letters1[size] = {0};
    int letters2[size] = {0};

    // Prompts the user to input strings to assign to str1 & str2.
    cout << "Enter first string:\n";
    getline(cin, str1);
    cout << "Enter second string:\n";
    getline(cin, str2);

    // We count how many times letters appear in each string and store those
    // values in two different arrays.
    find_letters(letters1, str1);
    find_letters(letters2, str2);

    // Compares the two arrays to see if each array has the same count for each
    // letter in each string.
    are_anagrams(letters1, letters2);

    return 0;
}



// Only takes an int array of size 26 and a string.
void find_letters(int letters[26], string str){

    // This for loop iterates over every character in the inputted string.
    for (int i = 0; i < str.length(); i++){

        // This for loop is used to iterate over the ASCii alphabet and
        // the inputted array simultaneously.
        for (int j = 0; j < 26; j++){

            // if the ASCii values of the current character, the for loop is on, is equal
            // to the the value of the uppercase or lowercase letter the smaller for
            // loop is on, then the corresponding index of the inputted array is incremented by 1.
            if ((str[i] == j + 65) || (str[i] == j + 97)){
                letters[j] += 1;
            }
        }
    }
 
}

// Only takes int arrays of size 26, that represent two strings.
void are_anagrams(int letters1[26], int letters2[26]){

    // This for loop iterates over all 26 elements of both arrays.
    for (int i = 0; i < 26; i++){

        // If at any time the two arrays do not have the same value in the
        // same index, then the strings are not anagrams and prints out a
        // statement saying so. The function then quits.
        if (letters1[i] != letters2[i]){
            cout << "The strings are not anagrams.\n";
            return;
        }
    }
    // If all the previous if statements weren't satisfied, then the strings are anagrams.
    cout << "The strings are anagrams.\n";
    return;
}
