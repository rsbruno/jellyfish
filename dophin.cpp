#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TAG
{
    string name;
    int amount = 1;
    TAG *next;
};

struct POSITION_TAG
{
    int pos;
    POSITION_TAG *next;
};

struct GENERIC_TAG
{
    TAG *HEAD = NULL;
};

struct GENERIC_POSITION_TAG
{
    POSITION_TAG *HEAD = NULL;
};

GENERIC_TAG *TagList = new GENERIC_TAG;

GENERIC_POSITION_TAG *TagPos = new GENERIC_POSITION_TAG;

void insertTag(string n)
{
    TAG *t = new TAG;
    TAG *aux = TagList->HEAD, *aux2 = TagList->HEAD;

    while (aux2 != NULL)
    {
        if (aux2->name == n)
        {
            aux2->amount++;
            return;
        }
        aux2 = aux2->next;
    }

    if (n[0] == '/')
        return;

    t->name = n;
    t->next = NULL;
    if (aux == NULL)
    {
        aux = t;
        TagList->HEAD = aux;
        return;
    }
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = t;
    return;
}

void PrintListTags(TAG *l)
{
    if (l == NULL)
        return;
    cout << l->amount;
    cout << " | ";
    cout << l->name;
    cout << '\n';
    PrintListTags(l->next);
}

void insertPositionTag(int n)
{
    POSITION_TAG *t = new POSITION_TAG;
    POSITION_TAG *aux = TagPos->HEAD;
    t->pos = n;
    t->next = NULL;
    if (aux == NULL)
    {
        aux = t;
        TagPos->HEAD = t;
        return;
    }

    while (aux->next != NULL)
        aux = aux->next;
    aux->next = t;
    return;
}

void PrintPositionTag(POSITION_TAG *l)
{
    if (l == NULL)
        return;
    cout << l->pos;
    cout << " - ";
    PrintPositionTag(l->next);
}

void SearchToTags(GENERIC_POSITION_TAG *t, string l)
{
    for (int i = 0; i < l.length(); i++)
    {
        if (l[i] == '<' && l[i + 1] != '<')
            insertPositionTag(i);
    }
}

int main()
{
    ifstream input("input.txt");
    string line;
    int i = 0;

    while (getline(input, line))
    {
        i++;
        TagPos->HEAD = NULL;
        SearchToTags(TagPos, line);
        POSITION_TAG *AuxPosi = TagPos->HEAD;

        while (AuxPosi != NULL)
        {
            int a = AuxPosi->pos;
            string name = "";
            while (line[++a] != '>' && line[a] != ' ')
                name += line[a];
            insertTag(name);
            AuxPosi = AuxPosi->next;
        }

        //PrintPositionTag(TagPos->HEAD);
    }
    cout << i;
    cout << " linhas analisadas\n";
    PrintListTags(TagList->HEAD);
}