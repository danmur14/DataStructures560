/*
* @file: SkewHeap.h
* @author: Daniel Murga
* @date: 2017.3.26
* @brief: Header file for SkewHeap.cpp
*/

#ifndef SkewHeap_h
#define SkewHeap_h
#include <fstream>
#include <iostream>

struct NodeS
{
    //NodeS properties
    int key;
    struct NodeS *m_left;
    struct NodeS *m_right;

    //normal constructor not used
    NodeS()
    {
        key = 0;
        m_left = nullptr;
        m_right = nullptr;
    }

    //used constructor with value
    NodeS(int val)
    {
        key = val;
        m_left = nullptr;
        m_right = nullptr;
    }

    //destructor
    ~NodeS()
    {
        delete m_left;
        delete m_right;
    }
};

class SkewHeap
{
  public:
    SkewHeap(int size);
    ~SkewHeap();
    void build(int data[], int size);
    bool insert(int value);
    bool deleteMin();
    NodeS* merge(NodeS* H1, NodeS* H2);
    void inOrder();
    void preOrder();
    void levelOrder();

  private:
    NodeS *m_root;
    void preOrder(NodeS* cNode);
	void inOrder(NodeS* cNode);
    int height(NodeS* cNode);
    void swapChildren(NodeS * H1);
    void levelOrder(NodeS* cNode, int level);

};

#endif