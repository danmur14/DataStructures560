/*
* @file: NodeQD.hpp 
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: Defines the methods for a templated NodeQD
*/

#include "NodeQD.h"
#include <string>

 
template <typename T>
NodeQD<T>::NodeQD()
{
    m_next = nullptr;
    m_previous = nullptr;
    m_value = -1;
    flag = false;
}

template <typename T>
void NodeQD<T>::setValue(T val)
{
    m_value = val;
}

template <typename T>
T NodeQD<T>::getValue() 
{
    return(m_value);
}

template <typename T>
void NodeQD<T>::setFlag(bool empty) 
{
    flag = empty;
}

template <typename T>
bool NodeQD<T>::getFlag() 
{
    return(flag);
}

template <typename T>
void NodeQD<T>::setNext(NodeQD<T>* next)
{
    m_next = next;
}

template <typename T>
NodeQD<T>* NodeQD<T>::getNext() 
{
    return(m_next);
}

template <typename T>
void NodeQD<T>::setPrevious(NodeQD<T>* prev)
{
    m_previous = prev;
}

template <typename T>
NodeQD<T>* NodeQD<T>::getPrevious() 
{
    return(m_previous);
}