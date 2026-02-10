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
    // argv[1] = option, argv[2] = value.
    if (argc != 3){
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>\n";
        exit(1);
    }

    // Convert C-string arguments into C++ strings for easier manipulation.
    string arg1(argv[1]), arg2(argv[2]);

    // If option is decimal-to-binary (d2b) OR decimal-to-hex (d2h).
    if ( (arg1 == "d2b") || (arg1 == "d2h") ){
        // arg1[2] is the third character, so either 'b' or 'h'.
        // This is used to tell dec2bh whether to convert to binary or hex.
        string hexaBinary = dec2bh(arg2, arg1[2]);
        // Print a label depending on conversion type.
        if (arg1[2] == 'b'){
            cout << "The value in binary is: ";
        }
        else{
            cout << "The value in hexadecimal is: ";
        }
        cout << hexaBinary << endl;

    }
    // If option is binary-to-decimal (b2d).
    else if (arg1 == "b2d"){
        // Convert a binary string to an int.
        int decimal = bin2d(arg2);
        // bin2d returns -1 to signal "invalid binary string".
        if (decimal == -1){
            cout << "Binary value contains non-binary digits.\n";
            exit(1);
        }
        else{
            cout << "The value in decimal is: " << decimal << endl;
        }
    }
    // Any other option is invalid.
    else{
        cerr << "Usage: converter <options: d2b, d2h, b2d> <value>\n";
        exit(1);
    }

    return 0;
}

// Pre-conditions:
//   1. binstring should be a string of only characters '0' and '1'.
// Post-conditions:
//   1. Returns the decimal (base-10) value of the binary string.
//   2. Returns -1 if any character is not '0' or '1'.
int bin2d(string binstring){
    int sum = 0;
    // Goes left-to-right. For each '1' in binstring, add 2^(positon of '1' from the right) to the sum.
    for (int i = 0; i < binstring.length(); i++){
        if (binstring[i] == '1'){
            sum += pow(2, (binstring.length() - 1) - i);
        }
        // Any non-binary digit makes the input invalid.
        else if (binstring[i] != '0'){
            return -1;
        }
    }

    return sum;
}

// Pre-conditions:
//   1.sdec is a string of a non-negative integer.
//   2. sdec should be within the range of int (because stoi is used).
//   3. bh is either:
//       'b' for binary output, or
//       'h' for hexadecimal output
// Post-conditions:
//   1. Returns the binary or hex string representation of the decimal input.
//   2. For input "0", returns "0".
string dec2bh(string sdec, char bh){
    int quot(stoi(sdec)), remain(0);// quot is the current quotient; remain is remainder.
    string hexBin = "";// will build the answer as a string.
    // Special case: 0 in any base is "0".
    if (quot == 0){
        return "0";
    }
    // Decimal to Binary conversion(repeated division by 2).
    if (bh == 'b'){
        while (quot != 0){
            remain = quot % 2;// remainder is next binary digit (0 or 1).
            quot = quot / 2;// reduces the quotient.
            // Insert digit at the front since we're generating digits least-significant-first.
            if (remain == 1){
                hexBin.insert(0, 1, '1');
            }
            else{
                hexBin.insert(0, 1, '0');
            }
        } 
    }
    // Decimal to Hex conversion(repeated division by 16).
    else if (bh == 'h'){
        while (quot != 0){
            remain = quot % 16;// remainder is next hex “digit” (0-15).
            quot = quot / 16;// reduce quotient.
            int number;// Will be used to compare to remain.
            
            // Maps remain to '0'-'9. If remain is less than 9.
            if (remain <= 9){
                number = 0;//set number equal to 0--the int representation of '0'.
                // Iterates through the characters '0' through '9' of the ASCII chart.
                for (char hex = '0'; hex <= '9'; hex++){
                    // The value of number is the integer representation of the current character of hex.
                    // Asserts if remain is equal to the current value of number.
                    if (remain == number){
                        hexBin.insert(0, 1, hex);// Insert digit at the front since we're generating digits least-significant-first.
                        break;// Breaks the loop to prevent redundant checks.
                    }
                    number++;// Increments number by 1
                }
            }
            // Maps remain to 'A'-'F'.
            else{
                number = 10;// Sets number equal to 10--the int representation of 'A'.
                // Iterates through the characters 'A' through 'F'.
                for (char hex = 'A'; hex <= 'F'; hex++){
                    // Asserts if remain is equal to the current value of number, and therefore equal to the character of hex.
                    if (remain == number){
                        hexBin.insert(0, 1, hex);// Insert digit at the front.
                        break;// Breaks the loop to prevent redundant checks.
                    }
                    number++;// Increments number by 1
                }
            }
        }

    }

    return hexBin;
}
