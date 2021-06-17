#include <iostream>
#include <string>
#include <tuple>

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

    tuple<stack *, stack *> search(string tag, stack *dad = NULL)
    {
        if ((this) == NULL)
            return {};
        if ((this)->get_name() == tag)
            return make_tuple((this), dad);
        return (this)->get_next()->search(tag, (this));
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
        cout << this->get_name() + '\n';
        (this)->get_next()->print();
    }

    stack *who_is_on_top() { return (this); }

    int what_to_do(string tag)
    {
        if (tag[0] == '/')
            return 1;
        if (tag[0] == '!')
            return 2;
        return 3;
    }

    bool remove(string tag)
    {
        stack *founded, *dad;
        tie(founded, dad) = (*this).search(replace_string(tag, '/'));
        if (founded == NULL)
            return false;

        if (dad == NULL)
        {
            if (founded->get_next() == NULL)
            {
                (*this).set_name("");
                (*this).set_next(NULL);
                return true;
            }
            (*this).set_name(founded->get_next()->get_name());
            (*this).set_next(founded->get_next()->get_next());
            return true;
        }
        dad->set_next(founded->get_next());
        return true;
    }

    bool pop()
    {
        if ((this)->get_next() == NULL && (this)->get_name() == "")
            return false;

        if ((this)->get_next() == NULL)
        {
            (this)->set_next(NULL);
            (this)->set_name("");
            return true;
        }
        (this)->set_name((this->get_next()->get_name()));
        (this)->set_next((this->get_next()->get_next()));
        return true;
    }
};