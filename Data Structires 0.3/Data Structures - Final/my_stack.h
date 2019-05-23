#pragma once
#include <stdexcept>
#include <iostream>
#include "global.h"

using namespace std;

template <class T> class my_stack
{
public:
	my_stack()
	{
		this->head = new node<T>;
		this->tail = new node<T>;
		this->size = 0;
	}
	my_stack(T value)
	{
		node<T>* temp = new node<T>;
		this->head = new node<T>;
		this->tail = new node<T>;

		temp->payload = value;
		this->setHead(temp);
		this->setTail(temp);
		this->size = 1;
	}

	//Setters
	void setHead(node<T>* newHead)			{	this->head = newHead;	}
	void setTail(node<T>* newTail)			{	this->tail = newTail;	}

	//Getters
	node<T>* getHead()						{	return this->getHead;	}
	node<T>* getTail()						{	return this->tail;		}
	size_t getSize()						{	return this->size;	    }

	void push(T value)
	{
		node<T>* temp = new node<T>;
		temp->payload = value;
		if (size == 0)
		{
			this->setHead(temp);
			this->setTail(temp);
			this->size += 1;
		}
		else if (size == 1)
		{
			temp->next = this->tail;	//Tail is base, head is top.
			this->tail->prev = temp;
			this->setHead(temp);
			this->size += 1;
		}
		else
		{
			temp->next = this->head;
			this->head->prev = temp;
			this->setHead(temp);
			this->size += 1;
		}
	}

	T pop()
	{
		try
		{
			if (this->getSize() == 0)
			{
				throw out_of_range("Index out of bounds\n");
			}
			else
			{
				node<T>* temp = new node<T>;
				temp = this->head;
				this->head = this->head->next;
				this->size -= 1;
				return temp->payload;
			}
		}
		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

private:
	node<T>* head;
	node<T>* tail;
	size_t size;
};