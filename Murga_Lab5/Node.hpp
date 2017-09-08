/*
* @file: Node.hpp 
* @author: Daniel Murga
* @date: 2017.3.1
* @brief: Defines the methods for a templated node
*/

#include "Node.h"
#include <string>

 
template <typename T>
Node<T>::Node()
{
    m_left = nullptr;
    m_right = nullptr;
    m_value = T();
}

template <typename T>
void Node<T>::setValue(T val)
{
    m_value = val;
}

template <typename T>
T Node<T>::getValue() 
{
    return(m_value);
}

template <typename T>
void Node<T>::setRight(Node<T>* right)
{
    m_right = right;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left)
{
    m_left = left;
}

template <typename T>
Node<T>* Node<T>::getRight() 
{
    return(m_right);
}

template <typename T>
Node<T>* Node<T>::getLeft() 
{
    return(m_left);
}
