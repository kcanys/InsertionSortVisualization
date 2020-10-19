#include <iostream>
#include "insert.h"

int main()
{
    insert I;
    while (I.running())
    {
        I.render();
        I.update();
    }
    return 0;
}