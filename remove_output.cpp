#include "Inc\main.h"

int main()
{
    string math = "Output/math/math_", vocab = "Output/vocab/vocab_", participant = "Output/participant/";
    int ID = 0;
    for (ID = 0; ID <= MAX_FILE; ID++)
    {
        string name = string(to_string(MAX_FILE).length() - to_string(ID).length(), '0') + to_string(ID);
        unsigned int condition = remove((math + name + ".txt").c_str()) + remove((vocab + name + ".txt").c_str()) + remove((participant + name + ".txt").c_str());
        if (!condition)
            break;
    }

    return 0;
}