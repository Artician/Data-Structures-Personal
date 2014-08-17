#include <iostream>

using namespace std;

struct payload
{
  int ID;
  int x;
  int y;
  string name;
};

struct node
{
  node *prev;
  node *next;
  bool isRoot;
  payload data;
};

node *fillStruct(node *tmp);
void print(node *tmp);

int main(void)
{
  node *temp;
  node *list;
  node *iterator;

  bool done = false;
  int count = 0;
  char answer;

  do 
    {
      temp = new node();

      temp = fillStruct(temp);

      if (count == 0)
	{
	  list = new node();
	  list = temp;
	  list->prev = NULL;
	  list->next = NULL;
	  list->isRoot = true;
	}
      else
	{
	  list->next = temp;
	  temp->prev = list;
	  list = new node();
	  list = temp;
	}
      count++;

      cout << "Will more elements be added to the list?\n [Y or N]\n";

      cin >> answer;

      switch(answer)
	{ 
	case 'y':
	case 'Y':
	  break;
	case 'n':
	case 'N':
	  list->next = NULL;
	  done = true;
	  break;
	default:
	  break;
	}
    } while (!done);

  while (list->prev != NULL)
    {
      list = list->prev;
    }

  int identifier = 100;
  
  while(1)
    {
      list->data.ID = identifier;
      identifier++;
      if (list->next == NULL)
	   break;
      list = list->next;
    }

  while (list->prev != NULL)
    {
      list = list->prev;
    }

  while(1)
    {
      print(list);
      if(list->next == NULL)
	break;
      list = list->next;
    }

  return 0;
}

node *fillStruct(node *tmp)
{
  if (!tmp)
    {
      cerr << "Unauthorized access. Terminating program";
      return tmp;
    }

  cout << "Please enter the X value.\n";

  cin >> tmp->data.x;

  cout << "Please enter the Y value.\n";

  cin >> tmp->data.y;

  cout << "Please enter the data name\n";

  cin >>tmp->data.name;

  return tmp; 
}

void print(node *tmp)
{
  cout << "Identifier: " << tmp->data.ID << endl;
  cout << "         X: " << tmp->data.x << endl;
  cout << "         Y: " << tmp->data.y << endl;
  cout << "      Name: " << tmp->data.name << endl;
}
