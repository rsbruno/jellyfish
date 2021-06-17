#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream input("input.txt");
    string line;
    int i = 0;
    while (getline(input, line))
    {

        cout<<line+"\n";
    }
    cout << i;
    cout << " linhas analisadas\n";
}