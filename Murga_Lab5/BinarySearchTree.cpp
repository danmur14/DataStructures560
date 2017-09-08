/*
* @file: BinarySearchTree.cpp
* @author: Daniel Murga
* @date: 2015.3.1
* @brief: Implements data structure
*/

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    m_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    while (m_root != nullptr)
    {
        deleteMin();
    }
}

bool BinarySearchTree::insert(int value)
{
    if (m_root == nullptr)
    {
        m_root = new Node<int>();
        m_root->setValue(value);
        return true;
    }
    else
    {
        return (insert(value, m_root));
    }
}

bool BinarySearchTree::insert(int value, Node<int> *&subtree)
{
    if (value == subtree->getValue())
    {
        return false;
    }

    if (value < subtree->getValue())
    {
        if (subtree->m_left == nullptr)
        {
            Node<int> *tmp = new Node<int>();
            tmp->setValue(value);
            subtree->m_left = tmp;
            return true;
        }
        else
        {
            return (insert(value, subtree->m_left));
        }
    }
    else
    {
        if (subtree->m_right == nullptr)
        {
            Node<int> *tmp = new Node<int>();
            tmp->setValue(value);
            subtree->m_right = tmp;
            return true;
        }
        else
        {
            return (insert(value, subtree->m_right));
        }
    }
}

bool BinarySearchTree::remove(int value)
{
    if (m_root == nullptr)
    {
        return false;
    }
    else if (search(value) == nullptr)
    {
        return false;
    }
    else if (value == m_root->getValue())
    {
        if (m_root->m_right != nullptr)
        {
            int min = getMin(m_root->m_right);
            remove(min);
            m_root->setValue(min);
            return true;
        }
        else if (m_root->m_left != nullptr)
        {
            Node<int> *tmp = m_root;
            m_root = m_root->m_left;
            delete tmp;
            return true;
        }
        else
        {
            delete m_root;
            m_root = nullptr;
        }
    }
    else
    {
        return (remove(value, m_root));
    }
}

bool BinarySearchTree::remove(int value, Node<int> *&subtree)
{
    // cases
    if (value == subtree->getValue())
    {
        // 0 children
        if (subtree->m_left == nullptr && subtree->m_right == nullptr)
        {
            delete subtree;
            subtree = nullptr;
        }
        // only left child
        else if (subtree->m_left != nullptr && subtree->m_right == nullptr)
        {
            Node<int> *tmp = subtree;
            subtree = subtree->m_left;
            delete tmp;
        }
        // only right child
        else if (subtree->m_right != nullptr && subtree->m_left == nullptr)
        {
            Node<int> *tmp = subtree;
            subtree = subtree->m_right;
            delete tmp;
        }
        // node to delete has two children
        else
        {
            int min = getMin(subtree->m_right);
            std::cout << min;
            subtree->setValue(min);
            deleteMin(subtree->m_right);
        }
        return true;
    }

    if (value < subtree->getValue())
    {
        return (remove(value, subtree->m_left));
    }
    else
    {
        return (remove(value, subtree->m_right));
    }
}

bool BinarySearchTree::deleteMin()
{
    if (m_root == nullptr)
    {
        return false;
    }
    else
    {
        int min = getMin(m_root);
        remove(min);
        return true;
    }
}

void BinarySearchTree::deleteMin(Node<int> *&subtree)
{
    if (subtree->m_left == nullptr)
    {
        remove(subtree->getValue(), subtree);
    }
    else
    {
        deleteMin(subtree->m_left);
    }
}

int BinarySearchTree::getMin(Node<int> *&subtree)
{
    if (subtree->m_left == nullptr)
    {
        return (subtree->getValue());
    }
    else
    {
        getMin(subtree->m_left);
    }
}

bool BinarySearchTree::deleteMax()
{
    if (m_root == nullptr)
    {
        return false;
    }
    else
    {
        int max = getMax(m_root);
        remove(max);
        return true;
    }
}

void BinarySearchTree::deleteMax(Node<int> *&subtree)
{
    if (subtree->m_right == nullptr)
    {
        remove(subtree->getValue(), subtree);
    }
    else
    {
        deleteMax(subtree->m_right);
    }
}

int BinarySearchTree::getMax(Node<int> *&subtree)
{
    if (subtree->m_right == nullptr)
    {
        return (subtree->getValue());
    }
    else
    {
        getMax(subtree->m_right);
    }
}

Node<int> *BinarySearchTree::search(int value)
{
    if (m_root == nullptr)
    {
        return nullptr;
    }
    else
    {
        return (search(value, m_root));
    }
}

Node<int> *BinarySearchTree::search(int value, Node<int> *&subtree)
{
    if (value == subtree->getValue())
    {
        return subtree;
    }

    if (value < subtree->getValue())
    {
        if (subtree->m_left == nullptr)
        {
            return nullptr;
        }
        else
        {
            return (search(value, subtree->m_left));
        }
    }
    else
    {
        if (subtree->m_right == nullptr)
        {
            return nullptr;
        }
        else
        {
            return (search(value, subtree->m_right));
        }
    }
}

void BinarySearchTree::preOrder()
{
    preOrder(m_root);
}

void BinarySearchTree::preOrder(Node<int> *&subtree)
{
    if (subtree != nullptr)
    {
        std::cout << subtree->getValue() << " ";
        preOrder(subtree->m_left);
        preOrder(subtree->m_right);
    }
}

void BinarySearchTree::inOrder()
{
    inOrder(m_root);
}

void BinarySearchTree::inOrder(Node<int> *&subtree)
{
    if (subtree != nullptr)
    {
        inOrder(subtree->m_left);
        std::cout << subtree->getValue() << " ";
        inOrder(subtree->m_right);
    }
}

void BinarySearchTree::levelOrder()
{
    Queue q;
    if (m_root == nullptr)
    {
        return;
    }
    else
    {
        Node<int> *subtree = m_root;
        q.Enqueue(m_root);

        while (!q.isEmpty())
        {
            subtree = q.Dequeue();
            std::cout << subtree->getValue() << " ";
            if (subtree->m_left != nullptr)
            {
                q.Enqueue(subtree->m_left);
            }
            if (subtree->m_right != nullptr)
            {
                q.Enqueue(subtree->m_right);
            }
        }
    }
}
