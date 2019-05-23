#include <iostream>
#include <stdexcept>
#include "global.h"
#pragma once

using namespace std;
template <class T> class my_list
{
public:
	my_list() //Creates an empty list
	{
		this->size = 0;
	}
	my_list(T data) //Takes one argument to create a list of size 1
	{
		node<T>* temp = new node<T>;

		temp->payload = data;
		//Come back to this for cleanup
		this->size = 1;
		this->head = temp;
		this->tail = temp;
	}
	~my_list()
	{
		delete this->head;
		delete this->tail;
		delete this->itr;

		size = 0;
	}


	void toHead() //Sets the iterator to the head node.
	{
		this->itr = this->head;
	}

	void toTail() //Sets the iterator to the tail node. *Note: Unused, included for completeness.
	{
		this->itr = this->tail;
	}


	T at(int pos) //Returns the value at a given position
	{
		try
		{
			if ((pos >= this->size)||(pos < 0))
			{
				throw(out_of_range("Index out of range.\n"));
			}

			else
			{
				this->toHead();

				for (int i = 0; i < pos; i++)
				{
					this->itr = this->itr->next;
				}

				return this->itr->payload;
			}
		}

		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}

	}

	size_t get_size()
	{
		return this->size;
	}

	void push_front(T data)
	{
		node<T>* temp = new node<T>;
		temp->payload = data;

		if (size == 0) //Empty list. Use same code as constructor to instantiate the pointers
		{
			//Come back to this for cleanup
			this->size += 1;
			this->head = temp;
			this->tail = temp;
		}
		else if (size == 1) //Head and tail point to the same object in memory. Split them from the head.
		{
			this->tail->prev = temp;
			temp->next = this->tail;
			this->head = temp;

			this->size += 1;
		}

		else
		{
			this->head->prev = temp;
			temp->next = this->head;
			this->head = temp;

			this->size += 1;
		}
	}

	void push_back(T data)
	{
		node<T>* temp = new node<T>;
		temp->payload = data;

		if (size == 0) //Empty list. Use same code as constructor to instantiate the pointers
		{
			//Come back to this for cleanup
			this->size += 1;
			this->head = temp;
			this->tail = temp;
		}
		else if (size == 1) //Head and tail point to the same object in memory. Split them from the head.
		{
			this->tail->prev = temp;
			temp->next = this->tail;
			this->head = temp;

			this->size += 1;
		}

		else
		{
			this->tail->next = temp;
			temp->prev = this->tail;
			this->tail = temp;

			this->size += 1;
		}
	}

	void insert_at(int pos, T data) //Insert a value at a given position
	{
		try
		{
			if ((pos >= this->size)||(pos < 0))
			{
				throw(out_of_range("Index out of range.\n"));
			}

			else
			{
				node<T>* temp = new node<T>;
				temp->payload = data;

				this->toHead();

				for (int i = 0; i < pos; i++)
				{
					this->itr = this->itr->next;
				}

				temp->prev = this->itr->prev;
				temp->next = this->itr;
				this->itr->prev->next = temp;
				this->itr->prev = temp;
				this->size += 1;
			}
		}
		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

	T pop_front()
	{
		try
		{
			if (this->size == 0)
			{
				throw(out_of_range("Index out of range.\n"));
			}

			else
			{
				T retVal;
				node<T>* temp = this->head;
				this->head = temp->next;

				this->size -= 1;

				retVal = temp->payload;

				return retVal;
			}
		}

		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

	T pop_back()
	{
		try
		{
			if (size == 0)
			{
				throw(out_of_range("Index out of range.\n"));
			}

			else
			{
				node<T>* temp = this->tail;
				this->tail = temp->prev;
				this->size -= 1;
				return temp->payload;
			}
		}
		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

	T remove_at(int pos) //Remove an item at a given position
	{
		try
		{
			if (size == 0)
			{
				throw(out_of_range("Index out of range.\n"));
			}
			else if ((pos >= this->size)||(pos < 0))
			{
				throw(out_of_range("Index out of range.\n"));
			}

			else
			{
				node<T>* temp;
				this->toHead();

				for (int i = 0; i < pos; i++)
				{
					this->itr = this->itr->next;
				}

				temp = this->itr;
				this->itr->prev->next = temp->next;
				this->itr->next->prev = temp->prev;

				this->size -= 1;

				return temp->payload;
			}
		}
		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}
	}

	void print_list()							//Let it be known: I do not want this function to even 
	{											//be in this program. It creates dependency problems, besides
		this->toHead();							//only arguably being valuable in debug, but if I can't check all
		for (int i = 0; i < this->size; i++)	//the boxes on the "Can he program at an undergraduate level?" list for
		{										//non-coders, nothing matters.
			cout << "Element " << i << ": " 
				<< this->itr->payload << endl;

			this->itr = this->itr->next;
		}
	}
private:
	node<T>* head;
	node<T>* tail;
	node<T>* itr;
	size_t size;
};