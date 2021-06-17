#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
    string name;
    stack *next;

    stack *search(string tag, stack *stck)
    {
        if (stck->get_next()->get_name() == tag)
        {
            //cout<<"tag->"+tag+" - "+get_name()+"\n";
            return stck;
        }
        return search(tag, stck->get_next());
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

    void insert_tag(string nm, stack *stck)
    {
        if (stck->get_next() == NULL)
        {
            if (stck->get_name() == "")
                stck->set_name(nm);
            else
                stck->set_next(new stack(nm));
            cout << "+ " + nm + "\n";
            return;
        }
        insert_tag(nm, stck->get_next());
    }

    void show_stack(stack *stck)
    {
        if (stck == NULL)
            return;
        cout << stck->get_name() + "\n";
        show_stack(stck->get_next());
    }

    stack *who_is_on_top(stack *stck)
    {
        if (stck->get_next() == NULL)
            return stck;
        return who_is_on_top(stck->get_next());
    }

    int analyze_tag(string tag)
    {
        if (tag[0] == '/')
            return 1; //pop
        if (tag[0] == '!')
            return 2; // invalid
        return 3;     //push
    }

};