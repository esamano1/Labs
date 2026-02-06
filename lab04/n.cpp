#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(){
    string s1 = "Howdy!";
    string s2 = "Doo!";
    cout << "before setting the width: \n" << s1 << endl << s2 << endl;
    cout << "after setting width using setw(): \n";
    cout << setw(6) << s1 << endl << setw(6) << s2 << endl;
    cout << setw(9) << s1 << endl << setw(9) << s2 << endl;
}
