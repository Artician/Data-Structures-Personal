#include "my_list.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template<class T>
my_list<T>::my_list()
{
	this->size = 0;
}

template<class T>
my_list<T>::my_list(T data)
{
	node<T>* temp;

	temp->payload = data;
	//Come back to this for cleanup
	this->size = 1;
	this->head = temp;
	this->tail = temp;
}

template <class T>
my_list<T>::~my_list()
{
	delete this->head;
	delete this->tail;
	delete this->itr;

	size = 0;
}

template <class T>
void my_list<T>::toHead()
{
	this->itr = this->head;
}

template <class T>
void my_list<T>::toTail()
{
	this->itr = this->tail;
}

template <class T>
T my_list<T>::at(int pos)
{
	try
	{
		if (pos >= this->size)
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

template <class T>
void my_list<T>::push_front(T data)
{
	node<T>* temp;
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

template <class T>
void my_list<T>::push_back(T data)
{
	node<T>* temp;
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

template<class T>
void my_list<T>::insert_at(int pos, T data)
{
	try
	{
		if (pos >= this->size)
		{
			throw(out_of_range("Index out of range.\n"));
		}

		else
		{
			node<T>* temp;
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

template <class T>
T my_list<T>::pop_front()
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

template <class T>
T my_list<T>::pop_back()
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

template <class T>
T my_list<T>::remove_at(int pos)
{
	try
	{
		if (size == 0)
		{
			throw(out_of_range("Index out of range.\n"));
		}
		else if (pos >= this->size)
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

template <class T>
void my_list<T>::print_list()
{
	this->toHead();
	for (int i = 0; i < this->size; i++)
	{
		cout << "Element " << i << ": " << this->itr->payload << endl;
	}
}