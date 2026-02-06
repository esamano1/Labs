#include <iostream>
void check_it(int a, int b, int c){
    if(a>b && b>c){
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}

int main()
{
    check_it(3,2,1);
    check_it(1,2,3);
    check_it(-1,-2,-3);
    check_it(3,3,1);
    check_it(3,2,2);
    check_it(0,0,0);

    return 0;
}
