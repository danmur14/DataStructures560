/*
* @file: MinHeap.cpp
* @author: Daniel Murga
* @date: 2015.3.5
* @brief: Implements data structure
*/

#include "MinHeap.h"

MinHeap::MinHeap(int size)
{
    m_size = size;
    t_elements = 0;
    heap = new int[m_size];
}

MinHeap::~MinHeap()
{
}

void MinHeap::build(int data[], int size)
{
    while (t_elements < size)
    {
        heap[t_elements] = data[t_elements];
        t_elements++;
    }

    int j = floor((t_elements - 1)/3);
    while (j >= 0)
    {
        heapify(j);
        j--;
    }
}

void MinHeap::heapify(int index) {
    //check children
    int child = 1;
    int childval;
    int parentval = heap[index];
    int min = parentval;
    int minIndex = index;

    while(child <= 3 && ((index*3) + child) < t_elements) {
        childval = heap[(index*3) + child];
        //set min value from children
        if(childval < min) {
            min = childval;
            minIndex = (index*3) + child;
        }
        child++;
    }
    //swap if needed
    if(min != parentval) {
        heap[index] = min;
        heap[minIndex] = parentval;
        //heapify where min was with new value
        heapify(minIndex);
    }
}

void MinHeap::heapifyParent(int index) {
    int parent = floor((index - 1)/3);
    int childval = heap[index];
    int parentval = heap[parent] ;
    if (parentval > childval)
    {
        heap[parent] = childval;
        heap[index] = parentval;
        heapifyParent(parent);
    }
}

bool MinHeap::insert(int value)
{
    int nextIndex = t_elements;
    heap[nextIndex] = value;
    t_elements++;

    heapifyParent(nextIndex);

    return true;
}

bool MinHeap::remove(int value)
{
    //check if heap is empty
    if(heap[0] == 0) {
        return false;
    }

    int firstParent = floor((t_elements - 2)/3);
    int startE = t_elements;
    int i = t_elements - 1;
    while(i != 0) {
        if(heap[i] == value) {
            int lastElement = heap[t_elements - 1];
            heap[i] = lastElement;
            heap[t_elements - 1] = 0;
            t_elements--;
            heapifyParent(i);
        }
        i--;
    }

    //no change in size, so value not found
    if(t_elements == startE) {
        return false;
    }
    else {
        return true;
    }
}

bool MinHeap::deleteMin()
{
    //check if heap is empty
    if(heap[0] == 0) {
        return false;
    }

    //get last element value and remove it
    int lastElement = heap[t_elements - 1];
    heap[t_elements - 1] = 0;
    t_elements--;

    //replace root with last element
    heap[0] = lastElement;
    heapify(0);

    return true;
}

bool MinHeap::deleteMax()
{
    //check if heap is empty
    if(heap[0] == 0) {
        return false;
    }

    //max value will always be on leaf
    int i = t_elements - 1;
    int firstParent = floor((i - 1)/3);
    int lastElement = heap[i];
    int max = heap[i];
    int maxIndex = i;

    //search each leaf node
    while(i != firstParent) {
        //set max and keep its index
        if(max < heap[i]) {
            max = heap[i];
            maxIndex = i;
        }
        i--;
    }

    //if it is the last element 
    if(maxIndex == t_elements - 1) {
        heap[t_elements - 1] = 0;
        t_elements--;
        return true;
    }
    else {
        heap[maxIndex] = lastElement;
        heap[t_elements - 1] = 0;
        t_elements--;
        heapifyParent(maxIndex);
        return true;
    }
}

void MinHeap::levelOrder()
{
    int level = 1;
    int rank = 0;
    int i = 0;
    std::cout << "\nLevel Order: " << std::endl;
    while (heap[i] != 0)
    {
        if (rank % 3 == 0 && rank > 0)
        {
            std::cout << "- ";
        }
        std::cout << heap[i] << " ";
        rank++;
        if(rank == level) {
            std::cout << std::endl;
            level = level * 3;
            rank = 0;
        }
        i++;
    }
}
