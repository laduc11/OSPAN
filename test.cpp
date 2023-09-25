#include "Inc\main.h"
int main()
{
    fstream current_state;
    current_state.open("Input/current_state.txt", ios::in);
    string temp;
    int ID;
    current_state >> temp >> ID;
    current_state.close();
    current_state.open("Input/current_state.txt", ios::out);
    temp = "ID:\t" + string(3 - to_string(ID + 1).length(), '0') + to_string(ID + 1);
    current_state << temp;
    current_state.close();

    return 0;
}