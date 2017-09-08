/*
* @file: BinarySearchTree.h
* @author: Daniel Murga
* @date: 2017.3.1
* @brief: Header file for BinarySearchTree.cpp
*/

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include "Node.h"
#include "queue.cpp"

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        bool insert(int value);
        bool remove(int value);
        bool deleteMin();
        bool deleteMax();
        Node<int>* search(int value);
        void preOrder();
        void inOrder();
        void levelOrder();
    private:
        Node<int>* m_root;
        bool insert(int value, Node<int>*& subtree);
        bool remove(int value, Node<int>*& subtree);
        void deleteMin(Node<int>*& subtree); 
        void deleteMax(Node<int>*& subtree); 
        Node<int>* search(int value, Node<int>*& subtree);
        int getMin(Node<int>*& subtree); 
        int getMax(Node<int>*& subtree); 
        void preOrder(Node<int>*& subtree);
        void inOrder(Node<int>*& subtree);
};

#endif