#pragma once
#include "global.h"
#include "my_list.h"
#include <stdexcept>
using namespace std;

template <class T> class my_vector : public my_list<T>
{
public:
	node<T>* at(int pos) //Returns the value at a given position
	{
		try
		{
			if ((pos >= this->size) || (pos < 0))
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

				return this->itr;
			}
		}

		catch (const out_of_range & oor)
		{
			cerr << oor.what();
		}

	}
	node<T>*& operator[](int index)
	{
		return this->at(index);
	}
private:
};