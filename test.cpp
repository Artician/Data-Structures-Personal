#include <iostream>
#include "redlist.h"

using namespace std;

int main()
{
    reDlist *myList;

    myList = new reDlist();

    bool done = false;

    int x, y;
    string name, input;
    char change, ans;

    x = 0;
    y = 0;

    do
    {

        cout << "Will this element be added to the front or back of the list?\n front or back:  ";
        cin >> input;
        cout << endl;

        if ((input == "front")||(input == "Front")||(input =="FRONT"))
        {
            change = 'f';
        }
        else if ((input == "back")||(input == "Back")||(input == "BACK"))
        {
            change = 'b';
        }
        else
        {
            change = 'i';
        }

        switch (change)
        {
        case 'f':
            {
                cout << "Please enter a value for X:  ";
                cin >> x;
                cout << "\n\n Please enter a value for Y:  ";
                cin >> y;
                cout << "\n\n Please enter a single word for the data:  ";
                cin >> name;

                myList->push_front(x, y, name);

                cout << endl << endl;
            }
            break;

        case 'b':
            {
                cout << "Please enter a value for X:  ";
                cin >> x;
                cout << "\n\n Please enter a value for Y:  ";
                cin >> y;
                cout << "\n\n Please enter a single word for the data:  ";
                cin >> name;

                myList->push_back(x, y, name);

                cout << endl << endl;
            }
            break;

        case 'i':
            {
                cout << "Invalid entry.\n\n";
            }

            break;
        }

        cout << "Is this the final element?\n Y or N: ";
        cin >> ans;

        switch (ans)
        {
        case 'y':
        case 'Y':
            done = true;
            break;

        case 'n':
        case 'N':
        default:
            break;
        }

    } while(!done);

    done = false;

    node *current = new node();



    do
    {
        bool done2 = false;

        cout << "Will you be accessing from the front or the back of the list?\n Front or Back:  ";

        cin >> input;

        if ((input == "Front")||(input == "front")||(input == "FRONT"))
        {
            change = 'f';
        }
        else if ((input == "Back")||(input == "back")||(input == "BACK"))
        {
            change = 'b';
        }
        else
        {
            change = 'i';
        }

        switch(change)
        {
        case 'f':
            {
                do
                {

                    current = myList->pop_front();

                    cout << "Name  : " << current->getName() << endl;
                    cout << "   X  : " << current->getX() << endl;
                    cout << "   Y  : " << current->getY() << endl;

                    current = myList->getRoot();

                    if (current->getNext() == NULL)
                    {
                        cout << "Name  : " << current->getName() << endl;
                        cout << "   X  : " << current->getX() << endl;
                        cout << "   Y  : " << current->getY() << endl;

                        done2 = true;
                    }

                } while (!done2);

            }
            done = true;
            break;

        case 'b':
            {
                do
                {

                    current = myList->pop_back();

                    cout << "Name  : " << current->getName() << endl;
                    cout << "   X  : " << current->getX() << endl;
                    cout << "   Y  : " << current->getY() << endl;

                    current = myList->getTail();

                    if (current->getPrev() == NULL)
                    {
                        cout << "Name  : " << current->getName() << endl;
                        cout << "   X  : " << current->getX() << endl;
                        cout << "   Y  : " << current->getY() << endl;
                        done2 = true;
                    }


                } while(!done2);

            }
            done = true;
            break;

        case 'i':
            {
                cout << "Invalid Input\n";
            }
            break;
        }

    } while (!done);

    return 0;
}
