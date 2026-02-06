#include <iostream>
using namespace std;

int main()
{
    int bar = 42;
    int car = 43, foo(3);
    int count(3);
    int reverse_count = 0;

    while (count != 0){
        cout << "Number: " << count << endl;
        cout << car/foo << ";" << bar << endl;
        car += 4;
        bar *= 2;
        count -= 1;
        reverse_count += 1;
    }
    cout << count << endl;
    cout << reverse_count << endl;
    cout << "All done!\n***Goodbye***\n";
    return 0;
}
