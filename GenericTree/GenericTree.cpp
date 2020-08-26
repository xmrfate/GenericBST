// GenericTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/* 
Programmer Name: Brandon Jinright
Program Name: Generic Tree
Description: C++ implementation of binary search tree
             using templates and smart pointers.
Date: 08/26/2020
*/

#include <iostream>
#include <memory>
#include "Tree.h"

using namespace std;
using namespace Tree;

int main()
{
    shared_ptr < BinarySearchTree<string> > bst  = make_shared < BinarySearchTree <string> >();
    bst->insert("Test");
    bst->insert("Brandon");
    bst->insert("Nothing");
    bst->insert("Apple");
    bst->insert("Brandy");
    bst->insert("Microsoft");
    bst->insert("Auburn");
    bst->insert("Football");
    bst->insert("Summer");
    bst->insert("Winter");
    bst->insert("Fall");
    
    // Inorder traversal of binary search tree
    bst->inorder();

    return 0;
}