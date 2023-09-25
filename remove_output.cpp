#include <windows.h>

using namespace std;

int main()
{
    system("del Output/math/*.txt");
    system("del Output/vocab/*.txt");
    system("del Output/participant/*.txt");
    return 0;
}