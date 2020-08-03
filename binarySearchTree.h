#pragma once
#include <iostream>
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "orderedLinkedList.h"
using namespace std;

struct nodeType
{
	nodeType* Llink,* Rlink, * newNode;
	int info;
};


template <class Type>
class binarySearchTree
{
public:
		binarySearchTree()
		{
			root = NULL;
			current = NULL;
			c = 0;
			for (int q = 0; q < 50; q++)
			{
				arr[q] = 1000000000;
			}
		}

		void insert(int num)
		{
			if (c < 50)
			{
				arr[c] = num;
				c++;
			}
			int z = 0;
			do
			{
				int min = arr[z];
				for (int i = z; i < 50; i++)
				{
					if (min <= arr[i])
					{
					}
					else
					{
						arr[z] = arr[i];
						arr[i] = min;
						min = arr[z];
					}
				}
				z++;

			} while (z < 50);

			int half = c / 2;
			half = half;

			nodeType* newNode = new nodeType();
			newNode->info = arr[half];
			newNode->Llink = NULL;
			newNode->Rlink = NULL;
			root = newNode;
			current = newNode;
			
			int x = 0;
			nodeType* LNode = new nodeType();
			nodeType* RNode = new nodeType();

			nodeType* nulled = new nodeType();
			nulled->info = NULL;
			nulled->Llink = NULL;
			nulled->Rlink = NULL;
			int d = half;

			do
			{
				if (d - 2 > 0 && d == half)
				{
					d = d - 2;
					LNode->info = arr[d];
					current->Llink = LNode;

					current = LNode;
					
					RNode->info = arr[d + 1];
					current->Rlink = RNode;
				}
				else if (d - 2 > 0)
				{
					d = d - 2;
					LNode->info = arr[d];
					RNode->info = arr[d + 1];
					current->Llink = LNode;

					current = LNode;
					current->Rlink = RNode;
				}
				else if (d - 2 == 0)
				{
					d = d - 2;
					LNode->info = arr[d];
					RNode->info = arr[d + 1];
					current->Llink = LNode;

					current = LNode;
					current->Rlink = RNode;
					current->Llink = nulled;
					x = -1;
				}
				else
				{
					LNode->info = arr[d - 1];
					RNode->info = arr[d + 1];
					current->Llink = LNode;
					current->Llink = RNode;
					x = -1;
				}
			} while (x != -1);

			int y = 0;
			int e = half;
			int here = 0;
			for (int i = 0; i < 50; i++)
			{
				if (arr[i] != 1000000000)
				{
					here++;
				}
			}

			do
			{
				if (d + 2 < here && d == half)
				{
					d = d + 2;
					RNode->info = arr[d];
					current->Llink = RNode;

					current = RNode;

					LNode->info = arr[d - 1];
					current->Llink = LNode;
				}
				else if (d + 2 < here)
				{
					d = d + 2;
					RNode->info = arr[d];
					LNode->info = arr[d - 1];
					current->Rlink = RNode;

					current = RNode;
					current->Llink = LNode;
					current->Rlink = nulled;
				}
				else if (d + 2 == here)
				{
					d = d + 2;
					RNode->info = arr[d];
					LNode->info = arr[d - 1];
					current->Rlink = RNode;

					current = RNode;
					current->Llink = LNode;
					current->Rlink = nulled;
					y = -1;
				}
				else
				{
					RNode->info = arr[d + 1];
					LNode->info = arr[d - 1];
					current->Rlink = RNode;
					current->Llink = LNode;
					y = -1;
				}
			} while (y != -1);
		}

		void inorderTraversal()
		{
			for(int i = 0; i < 50; i++)
			{
				if (arr[i] != 1000000000)
				{
					cout << arr[i] << " ";
				}
			}
			cout << endl;
		}

		int treeHeight()
		{
			int c = 0;
			for (int i = 0; i < 50; i++)
			{
				if (arr[i] != 1000000000)
				{
					c++;
				}
			}
			int a = c / 3;
			return a;
		}
		
		void createList <short int>(orderedLinkedList list)
		{
			for (int i = 0; i < 50; i++)
			{
				if (arr[i] != 1000000000)
				{
					using orderedLinkedList::insert;
					orderedLinkedList::list.insert(arr[i]);
				}
			}
		}

private:
	nodeType* root, *current;
	int arr[50];
	int c;

};
#endif
