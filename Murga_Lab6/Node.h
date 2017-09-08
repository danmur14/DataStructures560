/*
* @file: Node.h
* @author: Daniel Murga
* @date: 2017.3.1
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
    void setRight(Node<T>* right);
    Node<T>* getRight();
    void setLeft(Node<T>* left);
    Node<T>* getLeft();
    Node<T>* m_left;
    Node<T>* m_right;
    
private:
    T m_value;
    
};

#include "Node.hpp"
#endif