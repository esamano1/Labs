#include <iostream>
using namespace std;

void compute_coins(int amount);
// Precondition: 0 < amount < 100          
//Postcondition: The function prints out the number of quarters, dimes, and pennies needed to make the amount value


int main(){
    int cents(100);//sets cents to 100 so that the while loop can the first time 
    while(cents != 0){//repeats the loop as long as cents not equal to 0
        cout << "Enter number of cents (or zero to quit):\n";
        cin >> cents;//gets input
        if (cents == 0){//first, checks if user input 0, then exits if they did
            return 0;
        }
        else if (cents > 0 && cents < 100){//then, checks if cents is within the bounds 
            compute_coins(cents);//if cents is within bounds, the amount of change is given
                                 //in quarters, dimes, & pennies
        }
        else{//if rest of checks fail, then that must mean cents is out of bounds 0<c<100 and is not 0
            cout << "Amount is out of bounds. Must be between 1 and 99.\n";
        }
    }


    return 0;
}



void compute_coins(int amount){
// Precondition: 0 < amount < 100
    int total(amount), quarters, dimes, pennies;

    quarters = amount / 25;//divides by the int 25 to give the number of quarters, without the decimals.
                           //the int type of quarters also removes the decimal part.
    amount %= 25;//uses modulo to calculate what the remaining amount of cents is.
                 //this repeats for dimes and pennies as well.

    dimes = amount / 10;//uses the remaining amount of cents calculated above and divides by 10.
                        //same as the quarters, since dimes is of type int there is no decimals to the answer.
                        //this repeats for pennies below.
    amount %= 10;

    pennies = amount;
    amount %= 1;
    
    cout << total << " cents can be given in ";

    switch (quarters){//This switch statement determines what to print for quarters.
        case 0://if 0 quarters, then prints nothing.
            break;
        case 1://if 1 quarter,
            cout << "1 quarter";//prints this
            break;
        default://otherwise there are multiple quarters,
            cout << quarters << " quarters";//prints this generic phrase
            break;
    }

    switch (dimes){//This switch determines what to print for dimes.
        case 0:// if 0 dimes, then prints nothing
            break;
        case 1:// if 1 dime,
            if (quarters > 0){//checks the value of quarters, to determine if a comma is neccessary
                              //(applies to line 73 too)
                cout << ", ";
            }
            cout << "1 dime";//prints phrase for 1 dime.
            break;
        default://otherwise there are multiple dimes,
            if (quarters > 0){
                cout << ", ";
            }
            cout << dimes << " dimes";//prints generic phrase for dimes
            break;
    }

    switch (pennies){//This switch determines what to print for pennies.
        case 0://if 0 pennies.
            cout << ".\n";//prints a period
            break;
        case 1:// if 1 penny,
            if (dimes > 0 || quarters > 0){//checks the values of quarters and dimes, to determine if
                                           //a comma is neccessary(applies to line 92 too)
                cout << ", ";
            }
            cout << "1 penny.\n";//prints phrase for 1 penny
            break;
        default://otherwise there are multiple pennies,
            if (dimes > 0 || quarters > 0){
                cout << ", ";
            }
            cout << pennies << " pennies.\n";//prints generic phrase for pennies
            break;
    }            
//Postcondition: The function prints out the number of quarters, dimes, and pennies needed to make the amount value
}
