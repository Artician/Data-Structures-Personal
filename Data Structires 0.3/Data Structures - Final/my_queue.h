#pragma once
#include <stdexcept>
#include <iostream>
#include "global.h"


using namespace std;



template<class T> class my_queue : public my_list
{
public:
	//Constuctors
	my_queue()							//Empty queue							
	{
		this->head = new node<T>;
		this->tail = new node<T>;
		this->size = 0;
	}
	my_queue(T value)
	{
		node<T>* temp = new node<T>;
		
		this->head = new node<T>;
		this->tail = new node<T>;

		temp->payload = value;
		this->setHead(temp);
		this->setTail(temp);
		this->side = 1;
	}
	//Setters
	void setHead(node<T>* newHead)		{	this->head = newHead;	}
	void setTail(node<T>* newTail)		{	this->tail = newTail;	}
	void setSize(size_t newSize)		{	this->size = newSize;	}

	//Getters
	node<T>* getHead()					{	return this->head;	}
	node<T>* getTail()					{	return this->tail;	}
	size_t getSize()					{	return this->size;	}

	void push(T value)
	{
		node<T>* temp = new node<T>;
		temp->payload = value;

		if (this->getSize() == 0)
		{
			this->setTail(temp);
			this->size += 1;
		}
		else if (size == 1)
		{
			temp->next = this->tail;
			this->tail->prev = temp;
			this->setHead(temp);
			this->size += 1;
		}
		else
		{
			temp->next = this->getHead();
			this->head->prev = temp;
			this->setHead(temp);
			this->size += 1;
		}
	}

	T pop()
	{
		try
		{
			if (size == 0)
			{
				throw out_of_range("Index out of bounds\n");
			}
			else
			{
				node<T>* temp = new node<T>;
				temp = this->tail;
				this->tail = this->tail->prev;

				this->size -= 1;
				return temp->payload;
			}
		}
		catch (out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

private:
	node<T>* head;
	node<T>* tail;
	size_t size;
};