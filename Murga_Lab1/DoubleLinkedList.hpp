/*
* @file: DoubleLinkedList.hpp
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: Defines methods for the DoubleLinkedList
*/

#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Node<T>* temp;
    while(m_front != nullptr)
    {
        temp = m_front;
        m_front = m_front -> getNext();
        delete(temp);
    }
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
    return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::insert(T value) //insert
{
   insert(m_front, value);
}

template <typename T>
void DoubleLinkedList<T>::insert(Node<T>* head, T value) //insert
{
    //check non empty for value
    if(m_front != nullptr) {
        Node<T>* temp = find(m_front, value);
        if(temp != nullptr) {
            return;
        }
    }
    
    //recursive
    if(m_front == nullptr)
    {
        Node<T>* front;
        front = new Node<T>;
        front -> setValue(value);
        front -> setNext(nullptr);
        front -> setPrevious(nullptr);
        m_front = front;
        m_back = front;
        m_size++;
    }
    else
    {
        if(head->getNext() == nullptr) {
            Node<T>* n;
            n = new Node<T>;
            n -> setValue(value);
            n -> setNext(nullptr);
            n -> setPrevious(head);
            head -> setNext(n);
            m_back = n;
            m_size++;
        }
        else {
            insert(head->getNext(), value);
        }
    }
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
    remove(m_front, value);
}

template <typename T>
bool DoubleLinkedList<T>::remove(Node<T>* head, T value){
    if(m_front == nullptr) {
        return false;
    }

    if(head == nullptr) {
        return false;
    }
    else {
        if(head->getValue() == value) {
            if(m_size == 1) {
                delete (head);
                m_front = nullptr;
                m_size--;
                return true;
            }
            else if(m_front == head) {
                m_front = head->getNext();
                delete (head);
                m_front->setPrevious(nullptr);
                m_size--;
                return true;
            }
            else if(m_back == head) {
                m_back = head->getPrevious();
                delete (head);
                m_back->setNext(nullptr);
                m_size--;
                return true;
            }
            else {
                Node<T>* prev;
	            Node<T>* next;
                prev = head->getPrevious();
                next = head->getNext();
                prev->setNext(next);
                next->setPrevious(prev);
                delete (head);
                m_size--;
                return true;
            }
        }
        else {
            remove(head->getNext(), value);
        }
    }
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(Node<T>* head, T value) const
{
    if(head->getValue() == value) {
        return head;
    }
    else if(head->getNext() != nullptr) {
        find(head->getNext(), value);
    }
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
    Node<T> *front = m_front;
    std::cout << "List: ";
    while (front != nullptr)
    {
        std::cout << front->getValue() << " ";
        front = front->getNext();
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleLinkedList<T>::reverse()
{
    //base case
    if(m_size == 0 || m_size == 1) {
        return;
    }

    reverse(m_front);
    Node<T>* temp = m_front;
    m_front = m_back;
    m_back = temp;
}

template <typename T>
void DoubleLinkedList<T>::reverse(Node<T>* head){
    Node<T>* temp = head->getPrevious();
    head->setPrevious(head->getNext());
    head->setNext(temp);
    if(head->getPrevious() != nullptr) {
        reverse(head->getPrevious());
    }
}