#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);

int main ( int argc, char *argv[] ) {

    if (argc != 3){
        cout << "Usage: converter <options: d2b, d2h, b2d> <value>\n";
        exit(1);
    }

    string arg1(argv[1]), arg2(argv[2]);

    if ( (arg1 == "d2b") || (arg1 == "d2h") ){
        string hexaBinary = dec2bh(arg2, arg1[2]);
        cout << hexaBinary << endl;

    }
    else if (arg1 == "b2d"){
        int decimal = bin2d(arg2);
        if (decimal == -1){
            cout << "Binary value contains non-binary digits.\n";
            exit(1);
        }
        else{
            cout << "The value in decimal is: " << decimal << endl;
        }
    }
    else{
        cout << "Usage: converter <optins: d2b, d2h, b2d> <value>\n";
        exit(1);
    }
    // MISSING CODE HERE (you can remove these comments)
    // Check to see if the command-line arguments are being used correctly
    // Perform the conversion by calling the appropriate function
    // What happens next?!!?

    return 0;
}

// MISSING FUNCTION DEFINITIONS HERE 
// Make sure you have Pre-Conditions and Post-Conditions defined for each function you define here!
// (you can remove these comments) else{

int bin2d(string binstring){
    int sum = 0;
    for (int i = 0; i < binstring.length(); i++){
        if (binstring[i] == '1'){
            sum += pow(2, (binstring.length() - 1) - i);
        }
        else if(binstring[i] != '0'){
            return -1;
        }
    }
    return sum;
}

string dec2bh(string sdec, char bh){
    int quot(stoi(sdec)), remain(0);
    string hexBin = "";
    if (bh == 'b'){
        hexBin += "The value in binary is: ";
        while (quot != 0){
            remain = quot % 2;
            quot = quot / 2;
            if (remain == 1){
                hexBin.insert(24, 1, '1');
            }
            else{
                hexBin.insert(24, 1, '0');
            }
        } 
    }
    else if (bh == 'h'){
        hexBin += "The value in hexadecimal is: ";
        while (quot != 0){
            remain = quot % 16;
            quot = quot / 16;
            int number = 0;
            for (char hex = '0'; hex <= '9'; hex++){
                if (remain == number){
                    hexBin.insert(29, 1, hex);
                    break;
                }
                number++;
            }
            if (number == 10){//i could put if remain >= 9
                for (char hex = 'A'; hex <= 'F'; hex++){
                    if (remain == number){
                        hexBin.insert(29, 1, hex);
                        break;
                    }
                    number++;
                }
            }
        }

    }
    return hexBin;
}
