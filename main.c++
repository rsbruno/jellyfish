#include <iostream>
#include <fstream>
#include <string>

#include "./lib/constant.h"

#include "./classes/stack.c++"

using namespace std;

string extract_string(string line, int idx, int end)
{
    string result = "";
    for (idx++; idx < (end - 1); idx++)
        result += line[idx];
    return result;
}

string return_tag(string str)
{
    string tg = "";
    int array_size = sizeof(EXISTENT_TAGS) / sizeof(EXISTENT_TAGS[0]);

    int i = 0;
    while (str[i] != ' ' && str.length() > i)
        tg += str[i++];

    for (int i = 0; i < array_size; i++)
        if (tg == EXISTENT_TAGS[i])
            return tg;

    return "";
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
                while (line[i++] != '>' & v++ < SIZE_MAX_TAG)
                    ;
                string tag = extract_string(line, found, i);

                cout<<return_tag(tag);

                //cout << tag << endl;

                // switch (stck.what_to_do(tag))
                // {
                // case 1:
                //     //stck.pop();
                //     break;
                // case 2:
                //     break;
                // case 3:
                //     stck.push(tag);
                //     break;

                // default:
                //     cout << endl
                //          << "*\tTag ignorada -> " << tag << endl
                //          << endl;
                //     break;
                // }
            }
        }
    }
    //stck.print();
}