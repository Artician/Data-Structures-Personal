#ifndef LIST_INST_H_INCLUDED
#define LIST_INST_H_INCLUDED

#include "list.h"

template <typename T>
double_list<T>::double_list()
{
    this->head    = nullptr;
    this->tail    = nullptr;
    this->current = nullptr;

    this->sorted = false;
}

template <typename T>
double_list<T>::~double_list()
{
    delete this->current;
    delete this->head;
    delete this->tail;
}

template <typename T>
void double_list<T>::push_back(T data)
{
    if(tail)
    {
        node<T>* temp = new node<T>;
        temp->data = data;

        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }
    else
    {
        if(!head) //New list
        {
            this->tail = this->head = new node<T>;
            this->tail->prev = this->head->next = nullptr;
            this->tail->data = data;
        }
    }
}

template <typename T>
void double_list<T>::push_front(T data)
{
    if(head)
    {
        node<T>* temp = new node<T>;
        temp->data = data;

        this->head->prev = temp;
        temp->next = this->head;
        this->head = temp;
    }
    else
    {
        if(!tail) // Fresh new list
        {
            this->tail = this->head = new node<T>;
            this->head->data = data;
            this->tail = this->head;
        }
    }
}

template <typename T>
void double_list<T>::pop_back(T* out)
{
     if ( this->tail != nullptr )
    {
        *out = this->tail->data;
        if ( this->tail->prev != nullptr )
        {
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
        }
        else
            this->tail = this->head = nullptr;
    }
    else
        throw pop_empty();
}

template <typename T>
void double_list<T>::pop_front(T* out)
{
     if ( this->head != nullptr )
    {

        *out = this->head->data;
        if ( this->head->next != nullptr )
        {
            this->head = this->head->next;
            this->head->prev = nullptr;
        }
        else
            this->tail = this->head = nullptr;
    }
    else
        throw pop_empty();
}

#endif // LIST_INST_H_INCLUDED
