#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() {

    
    cout << fixed << showpoint;
    cout << setprecision(2);

    ifstream inputFile;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    inputFile.open(filename);
    if(inputFile.fail()){
        cerr << "Cannot open " << filename << endl;
        exit(1);
    }
    
    int lineCount(0), rhymeCount(0);
    string lastWord(""), nextWord("");
    while (getline(inputFile, nextWord)){
        lineCount++;
        nextWord = findLastWord(nextWord);
        cleanUp(nextWord);
        if (compareWords(lastWord, nextWord)){
            rhymeCount++;
            cout << lastWord << " and " << nextWord << endl;
        }
        lastWord = nextWord;
    }
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


string findLastWord(string line){
    string last = "";
    for (int i = line.length() - 1; i >= 0; i--){
        if (line[i] != ' '){
            last = line[i] + last;
        }
        else{
            break;
        }
    }
    
    return last;
}

void cleanUp(string &word){
    string temp = "";
    int wordLength = word.length();
    for (int i = 0; i < wordLength; i++){
        if ( (word[i] >= 'A') && (word[i] <= 'Z') ){
            temp += word[i] + 32;
        }
        else if ((word[i] >= 'a') && (word[i] <= 'z')){
            temp += word[i];
        }
    }
    word = temp;
    return;
}

bool compareWords(string word1, string word2){
    int length1(word1.length()), length2(word2.length());
    if ( (length1 < 2) || (length2 < 2) ){
        return false;
    }
    if ( (word1[length1 - 1] == word2[length2 - 1]) && (word1[length1 - 2] == word2[length2 - 2]) ){
        return true;
    }
    return false;
}
