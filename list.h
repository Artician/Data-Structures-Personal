#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


using namespace std;

template <typename T>
struct node
{
    T data;
    node* next = nullptr;
    node* prev = nullptr;
};

template <typename T>
class double_list
{
public:
    double_list();
    ~double_list();

    void push_front(T data);
    void push_back(T data);

    void pop_front(T* out);
    void pop_back(T* out);

    //virtual bool traverse();
    //virtual T access(int index);
    //virtual bool sort();
    //virtual int search(T term);
private:
    node<T>* head;
    node<T>* tail;
    node<T>* current;
    static unsigned int numel;
    bool sorted;
};

class pop_empty{};
#endif // LIST_H_INCLUDED
