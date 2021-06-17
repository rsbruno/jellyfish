#include <iostream>
#include <string>

using namespace std;

/*  ------------------------------------------------------------
    *   Para todos os casos o uso do "this" se refere
        a intância que chamou o método;
    *   Salvo nos casos de "*this", onde este define um ponteiro
        para onde está a instância na memória;
    ------------------------------------------------------------
*/

class stack
{
private:
    string name;
    stack *next;

    stack *search(string tag)
    {
        if ((this) == NULL)
            return NULL;
        if ((this)->get_name() == tag)
            return (this);
        return (this)->get_next()->search(tag);
    }

    string replace_string(string strg, char remove, string replace = "")
    {
        string result = "";
        for (int i = 0; i < strg.length(); i++)
            if (strg[i] != remove)
                result += strg[i];
            else
                result += replace;
        return result;
    }

public:
    stack(string nm = "", stack *nx = NULL)
    {
        name = nm;
        next = nx;
    }

    void set_name(string nm) { name = nm; }
    string get_name() { return name; }

    void set_next(stack *nx) { next = nx; }
    stack *get_next() { return next; }

    void push(string nm)
    {
        if ((this) == NULL)
            return;
        if ((this)->get_name() != "")
        {
            (this)->set_next(new stack(*this));
            (this)->set_name(nm);
        }
        else
            (this)->set_name(nm);
    }

    void print()
    {
        if ((this) == NULL)
            return;
        cout << (this)->get_name() + "\n";
        (this)->get_next()->print();
    }

    stack *who_is_on_top() {return (this);}

    int what_to_do(string tag)
    {
        if (tag[0] == '/')
            return 1; 
        if (tag[0] == '!')
            return 2; 
        return 3; 
    }
};