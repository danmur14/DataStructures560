/*
* @file: DoubleLinkedList.h
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Holds the public and private variables and methods of DoubleLinkedList
*/

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h
#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class DoubleLinkedList
{
public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    int size() const;
    void insert(T value);
    bool remove(T value);
    void printList() const;
    void reverse();
    Node<T>* find(T value) const;
    Node<T>* find(Node<T>* head, T value) const;

private:
    //helper functions for recursion
    void reverse(Node<T>* head);
    void insert(Node<T>* head, T value);
    bool remove(Node<T>* head, T value);
    Node<T>* m_front;
    Node<T>* m_back;
    int m_size;
};

#include "DoubleLinkedList.hpp"
#endif
