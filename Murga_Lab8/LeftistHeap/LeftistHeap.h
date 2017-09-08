/*
* @file: LeftistHeap.h
* @author: Daniel Murga
* @date: 2017.3.26
* @brief: Header file for LeftistHeap.cpp
*/

#ifndef LeftistHeap_h
#define LeftistHeap_h
#include <fstream>
#include <iostream>

struct NodeL
{
    //NodeL properties
    int rank;
    int key;
    struct NodeL *m_left;
    struct NodeL *m_right;

    //normal constructor
    NodeL()
    {
        key = 0;
        rank = 0;
        m_left = nullptr;
        m_right = nullptr;
    }

    //used constructor with value
    NodeL(int val)
    {
        key = val;
        rank = 1;
        m_left = nullptr;
        m_right = nullptr;
    }

    //destructor
    ~NodeL()
    {
        delete m_left;
        delete m_right;
    }
};

class LeftistHeap
{
  public:
    LeftistHeap(int size);
    ~LeftistHeap();
    void build(int data[], int size);
    bool insert(int value);
    bool deleteMin();
    NodeL *merge(NodeL *H1, NodeL *H2);
    void inOrder();
    void preOrder();
    void levelOrder();

  private:
    NodeL *m_root;
    void preOrder(NodeL *cNode);
    void inOrder(NodeL *cNode);
    int height(NodeL *cNode);
    void swapChildren(NodeL *H2);
    void levelOrder(NodeL *cNode, int level);
};

#endif