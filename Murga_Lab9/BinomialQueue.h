/*
* @file: BinomialQueue.h
* @author: Daniel Murga
* @date: 2017.3.26
* @brief: Header file for BinomialQueue.cpp
*/

#ifndef BinomialQueue_h
#define BinomialQueue_h
#include <fstream>
#include <iostream>

struct Node
{
    //Node properties
    int order;
    int key;
    struct Node *s_left;
    struct Node *f_child;
    struct Node *s_right;

    //normal constructor
    Node()
    {
        order = 0;
        key = 0;
        s_left = nullptr;
        s_right = nullptr;
        f_child = nullptr;
    }

    //used constructor with value
    Node(int val)
    {
        order = 0;
        key = val;
        s_left = nullptr;
        s_right = nullptr;
        f_child = nullptr;
    }

    //destructor
    ~Node()
    {
    }
};

#include "queue.cpp"

class BinomialQueue
{
  public:
    BinomialQueue();
    ~BinomialQueue();
    void build(int data[], int size);
    bool insert(int value);
    bool deleteMin();
    Node* merge(Node *H1, Node *H2);
    void levelOrder();

  private:
    Node *m_root;
    void levelOrder(Node *cNode);
};

#endif