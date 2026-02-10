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
    string userString, delimiter;

    cout << "Enter string to split:\n";
    getline(cin, userString);
    cout << "Enter delimiter string:\n";
    getline(cin, delimiter);
    
    vector<string> subStrs = split(userString, delimiter);

    if(subStrs.size() == 0){
        cout << "No substrings.\n";
    }
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

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments)
vector<string> split(string target, string delimiter){
    vector<string> subCollector;
    string subString = "";
    for (int i = 0; i < target.length(); i++){
        if (target[i] == delimiter[0]){
           if (subString != ""){
                subCollector.push_back(subString);
                subString = "";
           }
        }
        else if (i == target.length() - 1){
            subString += target[i];
            subCollector.push_back(subString);
            subString = "";
        }
        else{
            subString += target[i];
        }
    }
    
    return subCollector;
}
