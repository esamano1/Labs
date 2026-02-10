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

    
    // Expect exactly 2 command-line arguments after program name:
    // argv[1] = option, argv[2] = value
    if (argc != 3){
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>\n";
        exit(1);
    }

    // Convert C-string arguments into C++ strings for easier comparison/manipulation
    string arg1(argv[1]), arg2(argv[2]);

    // If option is decimal-to-binary (d2b) OR decimal-to-hex (d2h)
    if ( (arg1 == "d2b") || (arg1 == "d2h") ){
        // arg1[2] is the third character:
        // "d2b" -> 'b' ; "d2h" -> 'h'
        // This is used to tell dec2bh whether to convert to binary or hex.
        string hexaBinary = dec2bh(arg2, arg1[2]);
        if (arg1[2] == 'b'){
            cout << "The value in binary is: ";
        }
        else{
            cout << "The value in hexadecimal is: ";
        }
        cout << hexaBinary << endl;

    }
    // If option is binary-to-decimal (b2d)
    else if (arg1 == "b2d"){
        // Convert a binary string to an int
        int decimal = bin2d(arg2);
        // bin2d returns -1 to signal "invalid binary string"
        if (decimal == -1){
            cout << "Binary value contains non-binary digits.\n";
            exit(1);
        }
        else{
            cout << "The value in decimal is: " << decimal << endl;
        }
    }
    // Any other option is invalid
    else{
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>\n";
        exit(1);
    }

    return 0;
}

// bin2d
// Pre-conditions:
//   binstring should be a string of only characters '0' and '1'
// Post-conditions:
//   - Returns the decimal (base-10) value of the binary string
//   - Returns -1 if any character is not '0' or '1'
int bin2d(string binstring){
    int sum = 0;
    for (int i = 0; i < binstring.length(); i++){
        if (binstring[i] == '1'){
            sum += pow(2, (binstring.length() - 1) - i);
        }
        else if (binstring[i] != '0'){
            return -1;
        }
    }

    return sum;
}

// dec2bh
// Pre-conditions:
//   sdec is a string of a non-negative integer 
//   sdec should be within the range of int (because stoi is used)
//   bh is either:
//       'b' for binary output, or
//       'h' for hexadecimal output
// Post-conditions:
//   Returns the binary or hex string representation of the decimal input
//   For input "0", returns "0"
string dec2bh(string sdec, char bh){
    int quot(stoi(sdec)), remain(0);
    string hexBin = "";
    if (quot == 0){
        return "0";
    }
    if (bh == 'b'){
        while (quot != 0){
            remain = quot % 2;
            quot = quot / 2;
            if (remain == 1){
                hexBin.insert(0, 1, '1');
            }
            else{
                hexBin.insert(0, 1, '0');
            }
        } 
    }
    else if (bh == 'h'){
        while (quot != 0){
            remain = quot % 16;
            quot = quot / 16;
            int number;
            if (remain <= 9){
                number = 0;
                for (char hex = '0'; hex <= '9'; hex++){
                    if (remain == number){
                        hexBin.insert(0, 1, hex);
                        break;
                    }
                    number++;
                }
            }
            else{
                number = 10;
                for (char hex = 'A'; hex <= 'F'; hex++){
                    if (remain == number){
                        hexBin.insert(0, 1, hex);
                        break;
                    }
                    number++;
                }
            }
        }

    }

    return hexBin;
}
