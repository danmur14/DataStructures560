/*
* @file: MinHeap.h
* @author: Daniel Murga
* @date: 2017.3.5
* @brief: Header file for MinHeap.cpp
*/

#ifndef MinHeap_h
#define MinHeap_h
#include <fstream>
#include <iostream>
#include <cmath>

class MinHeap
{
    public:
        MinHeap(int size);
        ~MinHeap();
        void build(int data[], int size);
        bool insert(int value);
        bool remove(int value);
        bool deleteMin();
        bool deleteMax();
        void levelOrder();
    private:
        int m_size;
        int t_elements;
        int *heap;
        void heapify(int index);
        void heapifyParent(int index);
};

#endif