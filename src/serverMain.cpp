#include <iostream>
#include "component2/comp2.hpp"

main()
{
    Comp2 c2obj;
    int val = c2obj.c2method(99);
    std::cout << "Hello World! " << val;
    return 0;
}
