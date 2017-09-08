/*
* @file: Node.hpp 
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: Defines the methods for a templated node
*/

#include "Node.h"
#include <string>

 
template <typename T>
Node<T>::Node()
{
    m_next = nullptr;
    m_previous = nullptr;
    m_value = -1;
    flag = false;
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
void Node<T>::setFlag(bool empty) 
{
    flag = empty;
}

template <typename T>
bool Node<T>::getFlag() 
{
    return(flag);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    m_next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() 
{
    return(m_next);
}

template <typename T>
void Node<T>::setPrevious(Node<T>* prev)
{
    m_previous = prev;
}

template <typename T>
Node<T>* Node<T>::getPrevious() 
{
    return(m_previous);
}