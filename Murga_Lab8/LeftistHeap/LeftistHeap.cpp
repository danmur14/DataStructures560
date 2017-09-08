/*
* @file: LeftistHeap.cpp
* @author: Daniel Murga
* @date: 2015.3.26
* @brief: Implements data structure
*/

#include "LeftistHeap.h"

LeftistHeap::LeftistHeap(int size)
{
    m_root = nullptr;
}

LeftistHeap::~LeftistHeap()
{
    delete m_root;
}

void LeftistHeap::build(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(data[i]);
    }
}

bool LeftistHeap::insert(int value)
{
    NodeL *temp = new NodeL(value);
    m_root = merge(temp, m_root);
    return true;
}

bool LeftistHeap::deleteMin()
{
    //check if heap is empty
    if (m_root == nullptr)
    {
        return false;
    }

    NodeL *H1 = m_root->m_left;
    NodeL *H2 = m_root->m_right;
    NodeL *temp = nullptr;

    if (H1 == nullptr && H2 == nullptr)
    {
        m_root = nullptr;
        return true;
    }
    else if (H1 != nullptr && H2 == nullptr)
    {
        m_root = H1;
    }
    else if (H1 == nullptr && H2 != nullptr)
    {
        m_root = H2;
    }
    else
    {
        if (H1->key < H2->key)
        {
            m_root = H1;
            temp = H2;
        }
        else
        {
            m_root = H2;
            temp = H1;
        }
    }

    m_root = merge(m_root, temp);
    return true;
}

//H1 = new H2 = root
NodeL *LeftistHeap::merge(NodeL *H1, NodeL *H2)
{
    if (H1 == nullptr)
    {
        return H2;
    }
    else if (H2 == nullptr)
    {
        return H1;
    }
    else if (H1->key > H2->key)
    {
        NodeL *temp = H1;
        H1 = H2;
        H2 = temp;
    }

    H1->m_right = merge(H1->m_right, H2);
    //adjust rank(H1);
    if (H1->m_left != nullptr && H1->m_right != nullptr)
    {
        if (H1->m_left->rank < H1->m_right->rank)
        {
            swapChildren(H1);
        }
    }
    else if (H1->m_left == nullptr && H1->m_right != nullptr)
    {
        swapChildren(H1);
    }

    if (H1->m_right == nullptr)
    {
        H1->rank = 1;
    }
    else
    {
        H1->rank = H1->m_right->rank + 1;
    }

    return H1;
}

void LeftistHeap::swapChildren(NodeL *H1)
{
    NodeL *temp = H1->m_left;
    H1->m_left = H1->m_right;
    H1->m_right = temp;
}

int LeftistHeap::height(NodeL *cNode)
{
    if (m_root == nullptr)
    {
        return 0;
    }

    if (cNode->m_left == nullptr && cNode->m_right == nullptr)
    {
        return 1;
    }

    int left = 0;
    int right = 0;
    if (cNode->m_left != nullptr)
    {
        left = height(cNode->m_left);
    }
    if (cNode->m_right != nullptr)
    {
        right = height(cNode->m_right);
    }

    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

void LeftistHeap::inOrder()
{
    std::cout << "inorder: ";
    inOrder(m_root);
}

void LeftistHeap::inOrder(NodeL *cNode)
{
    if (cNode != nullptr)
    {
        inOrder(cNode->m_left);
        std::cout << cNode->key << " ";
        inOrder(cNode->m_right);
    }
}

void LeftistHeap::preOrder()
{
    std::cout << "preorder: ";
    preOrder(m_root);
}

void LeftistHeap::preOrder(NodeL *cNode)
{
    if (cNode != nullptr)
    {
        std::cout << cNode->key << " ";
        preOrder(cNode->m_left);
        preOrder(cNode->m_right);
    }
}

void LeftistHeap::levelOrder()
{
    int h = height(m_root);
    std::cout << "level order: " << std::endl;
    for (int i = 0; i < h; i++)
    {
        levelOrder(m_root, i);
        std::cout << "\n";
    }
}

void LeftistHeap::levelOrder(NodeL *cNode, int level)
{
    if (cNode == nullptr)
    {
        return;
    }

    if (level == 0)
    {
        std::cout << cNode->key << " ";
    }
    if (level - 1 >= 0)
    {
        levelOrder(cNode->m_left, level - 1);
        levelOrder(cNode->m_right, level - 1);
    }
}
