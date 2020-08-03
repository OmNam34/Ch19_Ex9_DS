#pragma once
#include <iostream>
#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
using namespace std;

struct listNodeType
{
	listNodeType* link, * newNode;
	int info;
};

template <class Type>
class orderedLinkedList
{
public:
	orderedLinkedList() //Constructor
	{
		first = NULL;
		last = NULL;
	}

	void insert(int num) //Inserts nodes to the end of the list. Defines the first and last nodes
	{
		listNodeType* newNode = new listNodeType();
		newNode->info = num;
		newNode->link = NULL;
		if (first == NULL)
		{
			first = newNode;
			last = newNode;
		}
		else
		{
			last->link = newNode;
			last = newNode;
		}
	}

	void print()
	{
		listNodeType* current = first;
		do
		{
			cout << current->info;
			current = current->link;
		} while (current->link != NULL);
	}

private:
	listNodeType* first, * last;
};
#endif