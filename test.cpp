#include "Inc\main.h"

int main()
{
    srand(time(0));
    for (int i = 0; i < 10; ++i)
    {
        cout << rand() % 20 << endl;
    }

    return 0;
}