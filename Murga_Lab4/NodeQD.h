/*
* @file: Node.h
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: Simple node holder that has all node variables and methods
*/

#ifndef NodeQD_h
#define NodeQD_h


template <typename T>
class NodeQD

{
public:
    NodeQD();
    void setValue(T val);
    T getValue();
    void setNext(NodeQD<T>* next);
    NodeQD<T>* getNext();
    void setPrevious(NodeQD<T>* prev);
    NodeQD<T>* getPrevious();
    void setFlag(bool empty);
    bool getFlag();
    
private:
    
    T m_value;
    NodeQD<T>* m_next;
    NodeQD<T>* m_previous;
    bool flag;
    
};

#include "NodeQD.hpp"
#endif