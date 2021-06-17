#include <iostream>
#include <fstream>
#include <string>

#include "./classes/Stack.c++"

using namespace std;

const int SIZE_MAX_TAG = 12;

string extract_string(string line, int idx, int end)
{
    string result = "";
    for (idx++; idx < (end - 1); idx++)
        result += line[idx];
    return result;
}

int main()
{
    ifstream input("input.txt");
    string line;

    stack stck = *new stack();
    while (getline(input, line))
    {

        int i = 0;
        for (i; i < line.length(); i++)
        {
            int found = -1;
            if (line[i] == '<')
            {
                found = i;
                int v = 0;
                while (line[i++] != '>' && v++ < SIZE_MAX_TAG)
                    ;
                string tag = extract_string(line, found, i);

                switch (stck.what_to_do(tag))
                {
                case 1:
                    //pop
                    break;
                case 3:
                    stck.push(tag);
                    break;
                default:
                    cout << "\n";
                    break;
                }
            }
        }
    }
    stck.print();
}