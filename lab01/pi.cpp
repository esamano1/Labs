#include <iostream>
using namespace std;
int main()
{
    const float pi = 3.1415;
    float diameter, area, circumference;

    cout << "Input the diameter for a circle and then press enter: ";
    cin >> diameter;

    area = pi*((diameter/2)*(diameter/2));
    circumference = pi*diameter;

    cout << "The area of this circle is: " << area << endl;
    cout << "The circumference of this circle is: " << circumference << endl;

    return 0;
}
