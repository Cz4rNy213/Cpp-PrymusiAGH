#include <iostream>
#include "add.h"

int main()
{
    extern int g_int;
    std::cout << "add(1,2) = " << add(1,2) << std::endl;
    std::cout << "SQR(2+3) = " << SQR(2+3);
    std::cout << "g_int = " << g_int << std::endl;
    int x=1, y = 0;
    std::cout<<x + y<<std::endl;
    return 0;
}
