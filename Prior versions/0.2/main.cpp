#include <iostream>
#include "list_inst.h"


using namespace std;

int main()
{
    double_list<int> myList1;
    double_list<int> myList2;
    double_list<int> myList3;
    double_list<int> myList4;

    bool finished = false;

    for(int i = 1; i <= 25; i++)
    {
        myList1.push_front(i);
        myList2.push_front(i);
        myList3.push_back(i);
        myList4.push_back(i);
    }

    cout << "First list (25 - 1) forward traversal:\n";
    while(!finished)
    {
        try
        {
            int val = 0;
            myList1.pop_front(&val);
            cout << val << ", ";
        }
        catch(pop_empty &bad_pop)
        {
            finished = true;
        }
    }
    cout << "\n\n";
    finished = false;

    cout << "Second list (25 - 1) reverse traversal:\n";
    while(!finished)
    {
        try
        {
            int val = 0;
            myList2.pop_back(&val);
            cout << val << ", ";
        }
        catch(pop_empty &bad_pop)
        {
            finished = true;
        }
    }
    cout << "\n\n";
    finished = false;

    cout << "Third list (1 - 25) forward traversal:\n";
    while(!finished)
    {
        try
        {
            int val = 0;
            myList3.pop_front(&val);
            cout << val << ", ";
        }
        catch(pop_empty &bad_pop)
        {
            finished = true;
        }
    }
    cout << "\n\n";
    finished = false;

    cout << "Fourth list(1 - 25) reverse traversal:\n";
    while(!finished)
    {
        try
        {
            int val = 0;
            myList4.pop_back(&val);
            cout << val << ", ";
        }
        catch(pop_empty &bad_pop)
        {
            finished = true;
        }
    }
    cout << "\n\n";
    finished = false;

    return 0;
}
