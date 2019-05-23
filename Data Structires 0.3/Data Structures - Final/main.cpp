
#include <iostream>
#include "my_vector.h"

using namespace std;

int main(void)
{
	bool done = false;
	//Variables for my_list testing
	//int select1, select2, select3, input1, position;
	//string input2;
	//my_list<int> list1;
	//my_list<string> list2("Jake");
	/*
	int select, input, temp_size;
	my_queue<int> queue1;

	do
	{
		cout << "Please enter a selection\n" << "1: Add an item\n"
			<< "2: Print queue and quit\n";
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "Enter a value\n";
			cin >> input;
			queue1.push(input);
			cout << "Queue is now " << queue1.getSize() << endl;
			break;
		case 2:
			temp_size = queue1.getSize();
			for (int i = 0; i < temp_size; i++)
			{
				cout << "Element " << i << ": " << queue1.pop() << endl;
			}
			done = true;
			break;
		default:
			break;
		}
	} while (!done);
	*/
	/*
	do
	{
		cout << "Which list to edit? 1 or 2. Enter 0 to quit\n";
		cin >> select1;

		switch (select1)
		{
		case 1:
			cout << "What will you do?\n" << "1: Add an element\n"
				<< "2: Remove an element\n" << "3: Access a specific element\n"
				<< "4: Print the list\n";
			cin >> select2;
			switch (select2)
			{
			case 1:
				cout << "Where to add it?\n" << "1: Front\n"
					<< "2: Back\n" << "3: Choose\n";
				cin >> select3;
				switch (select3)
				{
				case 1:
					cout << "Please input a value\n";
					cin >> input1;
					list1.push_front(input1);
					break;
				case 2:
					cout << "please input a value\n";
					cin >> input1;
					list1.push_back(input1);
					break;
				case 3:
					cout << "Please input a position and a value\n" 
						<< "Current size is: " << list1.get_size() << endl;
					cin >> position >> input1;
					list1.insert_at(position, input1);
					break;
				default:
					break;
				}
				break;
			case 2:
				cout << "Where to remove it?\n" << "1: Front\n"
					<< "2: Back\n" << "3: Choose\n";
				cin >> select3;
				switch (select3)
				{
				case 1:
					cout << "Value returned is: " << list1.pop_front() << endl;
					break;
				case 2:
					cout << "Value returned is: " << list1.pop_back() << endl;
					break;
				case 3:
					cout << "Please input a position\n" << "Current size is: " << list1.get_size() << endl;
					cin >> position;

					cout << "Value returned is: " << list1.remove_at(position);
					break;
				default:
					break;
				}
				break;
			case 3:
				cout << "Please input a position\n" << "Current size: " << list1.get_size() << endl;
				cin >> position;
				cout << "The element at position " << position << "has a value of: " << list1.at(position) << endl;
				break;
			case 4:
				list1.print_list();
				break;
			default:
				break;
			}
			break;
		case 2:
			cout << "What will you do?\n" << "1: Add an element\n"
				<< "2: Remove an element\n" << "3: Access a specific element\n"
				<< "4: Print the list\n";
			cin >> select2;
			switch (select2)
			{
			case 1:
				cout << "Where to add it?\n" << "1: Front\n"
					<< "2: Back\n" << "3: Choose\n";
				cin >> select3;
				switch (select3)
				{
				case 1:
					cout << "Please input a value\n";
					cin >> input2;
					list2.push_front(input2);
					break;
				case 2:
					cout << "please input a value\n";
					cin >> input2;
					list2.push_back(input2);
					break;
				case 3:
					cout << "Please input a position and a value\n"
						<< "Current size is: " << list2.get_size() << endl;
					cin >> position >> input2;
					list2.insert_at(position, input2);
					break;
				default:
					break;
				}
				break;
			case 2:
				cout << "Where to remove it?\n" << "1: Front\n"
					<< "2: Back\n" << "3: Choose\n";
				cin >> select3;
				switch (select3)
				{
				case 1:
					cout << "Value returned is: " << list2.pop_front() << endl;
					break;
				case 2:
					cout << "Value returned is: " << list2.pop_back() << endl;
					break;
				case 3:
					cout << "Please input a position\n" << "Current size is: " << list2.get_size() << endl;
					cin >> position;

					cout << "Value returned is: " << list2.remove_at(position);
					break;
				default:
					break;
				}
				break;
			case 3:
				cout << "Please input a position\n" << "Current size: " << list2.get_size() << endl;
				cin >> position;
				cout << "The element at position " << position << "has a value of: " << list2.at(position) << endl;
				break;
			case 4:
				list2.print_list();
				break;
			default:
				break;
			}
			break;
		case 0:
			done = true;
			cout << "Goodbye\n";
			break;
		default:
			break;
		}
	} while (!done);
	*/ //Testing code for my_list 
/*
my_stack<int> stack1;
int select, value, length;

do
{
	cout << "1: Add an element\n" << "2: list all and quit\n";
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "Enter a value\n";
		cin >> value;
		stack1.push(value);
		break;
	case 2:
		length = stack1.getSize();

		for (int i = 0; i < length; i++)
		{
			cout << "Element " << i << ": " << stack1.pop() << endl;
		}
		done = true;
		break;
	default:
		break;
	}
} while (!done);
*/

my_vector<int> vect1(1)
cin.get();
cin.get();
	return 0;
}