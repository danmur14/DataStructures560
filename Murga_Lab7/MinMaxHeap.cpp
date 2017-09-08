/*
* @file: MinMaxHeap.cpp
* @author: Daniel Murga
* @date: 2015.3.5
* @brief: Implements data structure
*/

#include "MinMaxHeap.h"

MinMaxHeap::MinMaxHeap(int size)
{
    m_size = size;
    t_elements = 1;
    heap = new int[m_size];
}

MinMaxHeap::~MinMaxHeap()
{
}

void MinMaxHeap::build(int data[], int size)
{
    while (t_elements - 1 < size)
    {
        heap[t_elements] = data[t_elements - 1];
        t_elements++;
    }

    int j = floor(t_elements / 2);
    while (j >= 1)
    {
        TrickleDown(j);
        j--;
    }
}

void MinMaxHeap::TrickleDown(int index)
{
    //check level
    if ((int)floor(log(index) / log(2)) % 2 == 0) //even min
    {
        TrickleDownMin(index);
    }
    else // odd max
    {
        TrickleDownMax(index);
    }
}

void MinMaxHeap::TrickleDownMax(int index)
{
    //check children
    int children[6];
    children[0] = 2 * index;
    children[1] = 2 * index + 1;
    children[2] = 2 * children[0];
    children[3] = 2 * children[0] + 1;
    children[4] = 2 * children[1];
    children[5] = 2 * children[1] + 1;
    int child = 0;
    int childval;
    int parentval;
    int max = heap[index];
    int maxIndex = index;

    if (0 < children[0] && children[0] < t_elements)
    {
        int i = 0;
        while (i < 6 && children[i] < t_elements)
        {
            if (heap[children[i]] > max)
            {
                max = heap[children[i]];
                maxIndex = children[i];
                child = i;
            }
            i++;
        }
    }

    //swap if needed
    if (maxIndex != index)
    {
        //grandchild
        if (1 < child)
        {
            int temp = heap[maxIndex];
            heap[maxIndex] = heap[index];
            heap[index] = temp;
            TrickleDownMax(maxIndex);
        }
        //child
        else
        {
            int temp = heap[maxIndex];
            heap[maxIndex] = heap[index];
            heap[index] = temp;
        }
    }
}

void MinMaxHeap::TrickleDownMin(int index)
{
    //check children
    int children[6];
    children[0] = 2 * index;
    children[1] = 2 * index + 1;
    children[2] = 2 * children[0];
    children[3] = 2 * children[0] + 1;
    children[4] = 2 * children[1];
    children[5] = 2 * children[1] + 1;
    int child = 0;
    int childval;
    int parentval;
    int min = heap[index];
    int minIndex = index;

    if (0 < children[0] && children[0] < t_elements)
    {
        int i = 0;
        while (i < 6 && children[i] < t_elements)
        {
            if (heap[children[i]] < min)
            {
                min = heap[children[i]];
                minIndex = children[i];
                child = i;
            }
            i++;
        }
    }

    //swap if needed
    if (minIndex != index)
    {
        //grandchild
        if (1 < child)
        {
            int temp = heap[minIndex];
            heap[minIndex] = heap[index];
            heap[index] = temp;
            TrickleDownMin(minIndex);
        }
        //child
        else
        {
            int temp = heap[minIndex];
            heap[minIndex] = heap[index];
            heap[index] = temp;
        }
    }
}

void MinMaxHeap::BubbleUp(int index)
{
    int parent = floor(index / 2);
    int childval = heap[index];
    int parentval = heap[parent];

    if (parentval == childval)
    {
        return;
    }

    if((int)floor(log(index) / log(2)) % 2 == 0) { //even min
		if (0 < parent && heap[index] > heap[parent]) {
			heap[index] = heap[parent];
			heap[parent] = childval;
			BubbleUpMax(parent);
		}
		else {
			BubbleUpMin(index);
		}
	}
	else { //max
		if (0 < parent && heap[index] < heap[parent]) {
			heap[index] = heap[parent];
			heap[parent] = childval;
			BubbleUpMin(parent);
		}
		else {
			BubbleUpMax(index);
		}
	}
}

void MinMaxHeap::BubbleUpMin(int index) {
    int parent = floor(index / 2);
    int grandparent = floor(parent / 2);
    int childval = heap[index];
    int grandval = heap[grandparent];

    if(0 < grandparent && childval < grandval) {
        heap[index] = grandval;
        heap[grandparent] = childval;
        BubbleUpMin(grandparent);
    }
}


void MinMaxHeap::BubbleUpMax(int index) {
    int parent = floor(index / 2);
    int grandparent = floor(parent / 2);
    int childval = heap[index];
    int grandval = heap[grandparent];

    if(0 < grandparent && childval > grandval) {
        heap[index] = grandval;
        heap[grandparent] = childval;
        BubbleUpMax(grandparent);
    }
}

bool MinMaxHeap::insert(int value)
{
    int nextIndex = t_elements;
    heap[nextIndex] = value;
    t_elements++;

    BubbleUp(nextIndex);

    return true;
}

bool MinMaxHeap::deleteMin()
{
    //check if heap is empty
    if (heap[1] == 0)
    {
        return false;
    }

    heap[1] = heap[t_elements - 1];
    heap[t_elements - 1] = 0;
    t_elements--;

    TrickleDown(1);

    return true;
}

bool MinMaxHeap::deleteMax()
{
    //check if heap is empty
    if (heap[1] == 0)
    {
        return false;
    }

    int maxIndex = 2;

	if(heap[3] > heap[2]) {
		maxIndex = 3;
	}

	int max = heap[maxIndex];
    heap[maxIndex] = heap[t_elements - 1];
    heap[t_elements - 1] = 0;
    t_elements--;

    TrickleDown(maxIndex);

    return true;
}

void MinMaxHeap::levelOrder()
{
    int level = 1;
    int rank = 0;
    int i = 1;
    std::cout << "\nLevel Order: " << std::endl;
    while (i < t_elements)
    {
        if (rank % 2 == 0 && rank > 0)
        {
            std::cout << "- ";
        }
        std::cout << heap[i] << " ";
        rank++;
        if (rank == level)
        {
            std::cout << std::endl;
            level = level * 2;
            rank = 0;
        }
        i++;
    }
}
