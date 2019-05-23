#pragma once
template<class T> struct node
{
	node<T>* prev;
	node<T>* next;
	T payload;
};