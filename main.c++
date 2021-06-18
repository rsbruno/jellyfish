#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

#include "./lib/constant.h"

#include "./classes/stack.c++"

stack LIST_TAGS = *new stack();
stack IGNORE = *new stack();

int count = 0;

using namespace std;

string format_tag(string str)
{
    string tg = "";
    int i = 0;
    while (str[i] != ' ' && str.length() > i)
        tg += str[i++];

    if (tg[tg.length() - 1] == '/')
        tg.erase(tg.length() - 1, tg.length());
    return tg;
}

string extract_string(string line, int idx, int end)
{
    string result = "";
    for (idx++; idx < (end - 1); idx++)
        result += line[idx];
    return result;
}

string return_tag(string str)
{
    stack *founded, *dad;
    tie(founded, dad) = LIST_TAGS.search(format_tag(str));

    if (founded != NULL)
        return founded->get_name();

    return "";
}

bool contain(string str, string el)
{
    for (int i = 0; i < str.length() - 1; i++)
    {
        string pair = "" + str[i];
        if (pair == el)
            return true;
    }

    return false;
}

int main()
{

    //inserção da lista de tags válidas

    ifstream input("tags.txt");
    string line;

    bool isdefinition = false, jump = false;
    string variable = "";
    while (getline(input, line))
    {
        if (line[0] == '#')
        {
            isdefinition = !isdefinition;

            if (isdefinition)
                variable = extract_string(line, 0, line.length() + 1);
            else
                variable = "";
        }

        if (isdefinition && line[0] != '#')
        {
            if (variable == "LIST_TAGS")
                LIST_TAGS.push(line);
            if (variable == "IGNORE")
                IGNORE.push(line);
        }
    }

    //inserção da lista de tags válidas

    //Programa principal
    ifstream html("input.txt");
    stack stck = *new stack();
    bool ignore = false;
    string ignored_tag = "";
    while (getline(html, line))
    {

        int i = 0;
        for (i; i < line.length(); i++)
        {
            int found = -1;
            if (line[i] == '<')
            {
                found = i;
                int v = 0;
                while (line[++i] != '>' && v++ < SIZE_MAX_TAG)
                    ;
                string tag = extract_string(line, found, (i + 1));

                stack *founded, *dad;
                tie(founded, dad) = IGNORE.search(IGNORE.replace_string(format_tag(tag), '/'));

                if (founded != NULL)
                    ignore = !ignore;

                if (!ignore)
                {
                    if (tag[0] == '/')
                        cout << "";
                    else
                    {
                        string result = return_tag(tag);
                        if (result == "")
                            cout << "TAG não definda -> " << tag << endl;
                        else
                        {
                            stck.push(result);
                        }
                    }
                }
            }
        }
    }
    //IGNORE.print();
    stck.print();
}