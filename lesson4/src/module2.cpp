#include "module2.h" 
#include "module1.h" 
#include <iostream>

namespace Module2
{
    void PrintHello()
    {
        std::cout << "hello from module2!" << std::endl;
        Module1::PrintHello();
    }
}
