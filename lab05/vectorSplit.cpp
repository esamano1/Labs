#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);

int main() {
    //declare two strings that will hold user input.
    string userString, delimiter;
    
    // Prompt user for the string to be split.
    cout << "Enter string to split:\n";
    getline(cin, userString);
    
    // Prompt user for the delimiter.
    cout << "Enter delimiter string:\n";
    getline(cin, delimiter);

    // Call split() to break the input string into pieces.
    vector<string> subStrs = split(userString, delimiter);

    // If split() returned no substrings, report that then.
    if(subStrs.size() == 0){
        cout << "No substrings.\n";
    }
    // Otherwise print each substring in quotes, separated by commas.
    else{
        cout << "The substrings are: ";
        for (int i = 0; i < subStrs.size(); i++){
            cout << "\"" << subStrs[i] << "\"";
            if (i != subStrs.size() - 1){
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}

// split()
// Pre-conditions:
//   1. target is the string to be split.
//   2. delimiter is the delimiter string.
// Post-conditions:
//   1. Returns a vector of substrings from target
vector<string> split(string target, string delimiter){
    vector<string> subCollector;// stores all substrings that we extract.
    string subString = "";// accumulates characters for the current substring.

    // Scan through target one character at a time
    for (int i = 0; i < target.length(); i++){
        // If we see the delimiter, we split target at that point.
        if (target[i] == delimiter[0]){
            // Only store the substring if it's non-empty.
           if (subString != ""){
                subCollector.push_back(subString);
                subString = "";// reset to start building the next substring.
           }
        }
        // If we're at the last character, we have to make sure we include it.
        else if (i == target.length() - 1){
            subString += target[i];
            subCollector.push_back(subString);
            subString = "";
        }
        // Otherwise, this character is part of the current substring.
        else{
            subString += target[i];
        }
    }
    
    return subCollector;
}
