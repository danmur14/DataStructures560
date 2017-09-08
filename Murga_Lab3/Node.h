/*
* @file: Node.h
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: Simple node holder that has all node variables and methods
*/

#ifndef Node_h
#define Node_h


template <typename T>
class Node

{
public:
    Node();
    void setValue(T val);
    T getValue();
    void setNext(Node<T>* next);
    Node<T>* getNext();
    void setPrevious(Node<T>* prev);
    Node<T>* getPrevious();
    void setFlag(bool empty);
    bool getFlag();
    
private:
    
    T m_value;
    Node<T>* m_next;
    Node<T>* m_previous;
    bool flag;
    
};

#include "Node.hpp"
#endif