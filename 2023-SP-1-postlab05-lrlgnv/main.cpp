#include <iostream>
#include "funcs.h"
#include "TrianglePrinter.h"

using namespace std;

int main()
{
    TrianglePrinter t;

    for (int i =0; i < 7; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            t.add(combination(i,j));
        }
        t.newrow();
    }
    t.print();
    return 0;
}
