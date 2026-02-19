#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {

    // Format all floating-point output to show 2 decimals
    cout << fixed << showpoint;
    cout << setprecision(2);

    // Get input filename from user
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    // Open the file for reading
    ifstream inputFile;
    inputFile.open(filename);

    // If file couldn't be opened, print error message and exit
    if(inputFile.fail()){
        cerr << "Cannot open " << filename << endl;
        exit(1);
    }
    
    int lineCount(0), rhymeCount(0); // Total number of lines, and number of rhyming pairs
    string lastWord(""), nextWord(""); // lastWord holds previous line's last word, and nextWord holds the current line's last word

    // Read the file one line at a time, and add 1 to the line count
    while (getline(inputFile, nextWord)){
        lineCount++;

        // Extract the last word from the current line
        nextWord = findLastWord(nextWord);

        // lowercase and strip punctuation, digits, etc. from nextWord
        cleanUp(nextWord);

        // Compare previous line's last word to current line's last word
        // If the last two letters match, count it as a rhyme and print the pair of words
        if (compareWords(lastWord, nextWord)){
            rhymeCount++;
            cout << lastWord << " and " << nextWord << endl;
        }
        
        // Update lastWord to the current word for the next iteration
        lastWord = nextWord;
    }

    // Print results
    if (rhymeCount > 0){
        if (rhymeCount == 1){
            cout << "There is 1 pair of rhyming words.\n";
        }
        else{
            cout << "There are " << rhymeCount << " pairs of rhyming words.\n";
        }
        cout << "There are " << lineCount << " lines in this poem, so the rhyme-line density is: " << static_cast<double>(rhymeCount)/lineCount << endl;
    }
    else{
        cout << "No rhymes found.\n";
        cout << "There are " << lineCount << " lines in this poem.\n";
    }
    
    return 0;
}

// Pre-conditions:
//     line is any string
// Post-conditions:
//     Returns the chunk of characters after the last space.
//     If line ends with spaces, this function will return ""
string findLastWord(string line){
    // Initialize an empty string to store the characters of the last word
    string last = "";

    // Scan from the end of the line backwards until we hit a space
    for (int i = line.length() - 1; i >= 0; i--){
        if (line[i] != ' '){
            // Prepend character to build the word in correct order
            last = line[i] + last;
        }
        else{
            // stop at the first space encountered
            break;
        }
    }
    
    return last;
}

// Pre-conditions:
//     word is a string passed in by reference so it can be modified
// Post-conditions:
//     word contains only lowercase letters a-z
//     all punctuation, digits, spaces, etc. are removed
void cleanUp(string &word){
    // Initialize a an empty string to temporarily store only the lowercase letters in word
    string temp = "";

    // Copy only letters into temp, converting uppercase to lowercase
    for (int i = 0; i < word.length(); i++){
        if ( (word[i] >= 'A') && (word[i] <= 'Z') ){
            temp += word[i] + 32; // 'A'->'a', 'B'->'b', ...
        }
        else if ((word[i] >= 'a') && (word[i] <= 'z')){
            temp += word[i]; // already lowercase
        }
        // else: ignore non-letter characters
    }
    
    // replace original with cleaned version
    word = temp;
    return;
}

// Pre-conditions:
//     word1 and word2 are both strings and assumed to already be clean
// Post-conditions:
//     Returns true if both words have length >= 2 AND their last two letters match.
//     Returns false otherwise.
bool compareWords(string word1, string word2){
    int length1(word1.length()), length2(word2.length());

    // Need at least two letters in each word to compare last two characters
    if ( (length1 < 2) || (length2 < 2) ){
        return false;
    }

    // Check if last two letters are the same
    if ( (word1[length1 - 1] == word2[length2 - 1]) && (word1[length1 - 2] == word2[length2 - 2]) ){
        return true;
    }
    return false;
}
