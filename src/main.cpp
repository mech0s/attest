#include <iostream>
#include "component1/comp1.hpp"

main()
{
    Comp1 c1obj;
    int val = c1obj.c1method(99);
    std::cout << "Hello World! " << val;
    return 0;
}
