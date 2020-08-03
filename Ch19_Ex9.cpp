//Brad Nam
//CSC 161
//August 3, 2020
//Chapter 19 Program


//Data
//68 43 10 56 77 82 61 82 33 56 72 66 99 88 12 6 7 21 -999

#include <iostream>
#include "binarySearchTree.h"
#include "orderedLinkedList.h"

using namespace std;

int main()
{
    binarySearchTree<int>  treeRoot;
    orderedLinkedList<int> newList;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal();
    cout << endl;
    cout << "Tree Height: " << treeRoot.treeHeight()
        << endl;
   treeRoot.createList(newList);

    cout << "newList: ";
    newList.print();

    cout << endl;
    system("pause");

    return 0;
}