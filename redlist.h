/* ReDlist - a Rewrite of
 *           doubly linked lists
 *
 *           Author: Jacob Moses
 *
 *           Please attribute if
 *           you find this helpful!
 *
 *           Features to add:
 *
 *          1.) List traversal
 */

#ifndef REDLIST_H_INCLUDED
#define REDLIST_H_INCLUDED


//Payload struct to hold data. Edit as needed
struct payload
{
    int x;
    int y;
    std::string name;
};
class node
{
public:

    // Constructors
    node();
    node(int x, int y, std::string name);

    // Get Functions, used in other classes
    std::string getName();
    int getX();
    int getY();
    node* getPrev();
    node* getNext();


    //Set Functions, used to access data members
    void setX(int x);
    void setY(int y);
    void setName(std::string name);
    void setPrev(node* prev);
    void setNext(node* next);

private:

    // Non function members to the node class.
    payload *data;
    node *prev;
    node *next;
};

// This is the master class, the only one that needs to be called to create a list.
class reDlist
{
public:
    // Simple constructor.
   reDlist();

    // Overloads of push front and back functions.
   void push_back(int x, int y, std::string name);
   void push_front(int x, int y, std::string name);

   node* pop_back();
   node* pop_front();

    //Used for list navigation
   node* getRoot();
   node* getTail();

private:
    node *tmp;
    node *root;
    node *tail;


};

//Simple constructor
node::node()
{
    prev = NULL;
    next = NULL;
    data = NULL;
}

// Most used node constructor, takes arguments for int and string types
node::node(int x, int y, std::string name)
{
    //prev and next pointers initially set to null for security
    prev = NULL;
    next = NULL;

    // Allocates heap memory for data
    data = new payload();

    //Sets data members
    setX(x);
    setY(y);
    setName(name);
}

// Get and set functions, no comment needed
std::string node::getName()
{
    return data->name;
}

int node::getX()
{
    return data->x;
}

int node::getY()
{
    return data->y;
}

node* node::getNext()
{
    return this->next;
}

node* node::getPrev()
{
    return this->prev;
}

void node::setX(int x)
{
    data->x = x;
}

void node::setY(int y)
{
    data->y = y;
}

void node::setName(std::string name)
{
    data->name = name;
}

void node::setPrev(node* prev)
{
    this->prev = prev;
}

void node::setNext(node* next)
{
    this->next = next;
}
//End function definitions for node class

//===========================================//

//Begin function definition for reDlist class
reDlist::reDlist()
{
    // Initializes pointers to crucial node pointers
    tmp = new node();
    root = new node(0, 0, "XXXXXXX");
    tail = new node(0, 0, "XXXXXXX");

    //Links Root and Tail, so push and pop functions work
    root->setNext(tail);
    root->setPrev(NULL);

    tail->setNext(NULL);
    tail->setPrev(root);
}

// In depth documentation within the function
void reDlist::push_back(int x, int y, std::string name)
{
    // * Steps:
    // *
    // *    1 : Check if tail is in its default state

    if (tail->getName() == "XXXXXXX")
    {
        // *          a: Assign tail to new values
        tail->setX(x);
        tail->setY(y);
        tail->setName(name);
    }

    else
    {
        // *    2 : If not, assign existing tail to *tmp
        tmp = tail;
        // *    3 : Reallocate tail with new, using values
        tail = new node(x, y, name);
        // *    4 : Set tmp->next to tail
        tmp->setNext(tail);
        // *    5 : Set tail->prev to tmp
        tail->setPrev(tmp);
        // *    6 : Set tail->next to NULL
        tail->setNext(NULL);
    }
}

void reDlist::push_front(int x, int y, std::string name)
{
    // * Steps:
    // *
    // *    1 : Check if root is in its default state

    if (root->getName() == "XXXXXXX")
    {
        // *          a: Assign root to new values
        root->setX(x);
        root->setY(y);
        root->setName(name);
    }

    else
    {
        // *    2 : If not, assign existing root to *tmp
        tmp = root;
        // *    3 : Reallocate root with new, using values
        root = new node(x, y, name);
        // *    4 : Set tmp->prev to root
        tmp->setPrev(root);
        // *    5 : Set root->next to tmp
        root->setNext(tmp);
        // *    6 : Set root->prev to NULL
        root->setPrev(NULL);
    }
}

node* reDlist::pop_back()
{
    // *  Steps:
    // *      1: Set new temporary node with values
    node *retVal = new node(tail->getX(), tail->getY(), tail->getName());
    // *      2: Set tail to tail->prev
    tail = tail->getPrev();
    // *      3: Set tail->next to NULL
    tail->setNext(NULL);
    // *      4: Return new temporary node
    return retVal;
}

node* reDlist::pop_front()
{
    // *  Steps:
    // *      1: Set new temporary node with values
    node *retVal = new node(root->getX(), root->getY(), root->getName());
    // *      2: Set tail to root->next
    root = root->getNext();
    // *      3: Set root->prev to NULL
    root->setPrev(NULL);
    // *      4: Return new temporary node
    return retVal;
}

node* reDlist::getRoot()
{
    return root;
}

node* reDlist::getTail()
{
    return tail;
}

#endif // REDLIST_H_INCLUDED
