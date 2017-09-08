/*
* @file: SkewHeap.cpp
* @author: Daniel Murga
* @date: 2015.3.26
* @brief: Implements data structure
*/

#include "SkewHeap.h"

SkewHeap::SkewHeap(int size)
{
    m_root = nullptr;
}

SkewHeap::~SkewHeap()
{
    delete m_root;
}

void SkewHeap::build(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(data[i]);
    }
}

bool SkewHeap::insert(int value)
{
    NodeS *temp = new NodeS(value);
    m_root = merge(temp, m_root);
    return true;
}

bool SkewHeap::deleteMin()
{
    //check if heap is empty
    if (m_root == nullptr)
    {
        return false;
    }

    NodeS *H1 = m_root->m_left;
    NodeS *H2 = m_root->m_right;
    NodeS *temp = nullptr;

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
NodeS *SkewHeap::merge(NodeS *H1, NodeS *H2)
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
        NodeS *temp = H1;
        H1 = H2;
        H2 = temp;
    }

    NodeS *temp;
    temp = H1->m_right;
    H1->m_right = H1->m_left;
    H1->m_left = merge(temp, H2);

    return H1;
}

void SkewHeap::swapChildren(NodeS *H1)
{
    NodeS *temp = H1->m_left;
    H1->m_left = H1->m_right;
    H1->m_right = temp;
}

int SkewHeap::height(NodeS *cNode)
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

void SkewHeap::inOrder()
{
    std::cout << "inorder: ";
    inOrder(m_root);
}

void SkewHeap::inOrder(NodeS *cNode)
{
    if (cNode != nullptr)
    {
        inOrder(cNode->m_left);
        std::cout << cNode->key << " ";
        inOrder(cNode->m_right);
    }
}

void SkewHeap::preOrder()
{
    std::cout << "preorder: ";
    preOrder(m_root);
}

void SkewHeap::preOrder(NodeS *cNode)
{
    if (cNode != nullptr)
    {
        std::cout << cNode->key << " ";
        preOrder(cNode->m_left);
        preOrder(cNode->m_right);
    }
}

void SkewHeap::levelOrder()
{
    int h = height(m_root);
    std::cout << "level order: " << std::endl;
    for (int i = 0; i < h; i++)
    {
        levelOrder(m_root, i);
        std::cout << "\n";
    }
}

void SkewHeap::levelOrder(NodeS *cNode, int level)
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
