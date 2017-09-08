/*
* @file: MinMaxHeap.h
* @author: Daniel Murga
* @date: 2017.3.11
* @brief: Header file for MinMaxHeap.cpp
*/

#ifndef MinMaxHeap_h
#define MinMaxHeap_h
#include <fstream>
#include <iostream>
#include <cmath>

class MinMaxHeap
{
    public:
        MinMaxHeap(int size);
        ~MinMaxHeap();
        void build(int data[], int size);
        bool insert(int value);
        bool deleteMin();
        bool deleteMax();
        void levelOrder();
    private:
        int m_size;
        int t_elements;
        int *heap;
        void TrickleDown(int index);
        void TrickleDownMin(int index);
        void TrickleDownMax(int index);
        void BubbleUp(int index);
        void BubbleUpMin(int index);
        void BubbleUpMax(int index);
};

#endif