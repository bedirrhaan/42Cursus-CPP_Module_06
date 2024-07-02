#include <iostream>
#include "Serializer.hpp"

int main()
{

    Data *x = new Data;  
    uintptr_t y = Serializer::serialize(x);
    Data *z = Serializer::deserialize(y);
    y = 21;
    z->i = 11;           
    std::cout << z->i << " and " << y << std::endl;

    delete x;
}

