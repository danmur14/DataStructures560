/*
* @file: queue.cpp
* @author: Daniel Murga
* @date: 2015.3.1
* @brief: Implements simple array queue
*/

const int MAX_SIZE = 100;

class Queue
{
  private:
    Node *queue[MAX_SIZE];
    int q_front;
    int q_back;

  public:
    Queue()
    {
        q_front = 0;
        q_back = 0;
    }

    void Enqueue(Node *node)
    {
        if (Size() == MAX_SIZE - 1)
        {
            return;
        }
        queue[q_back] = node;
        q_back = ++q_back % MAX_SIZE;
    }

    Node *Dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        Node *node = queue[q_front];
        q_front = ++q_front % MAX_SIZE;
        return node;
    }

    Node *Front()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        return queue[q_front];
    }

    int Size()
    {
        return abs(q_back - q_front);
    }

    bool isEmpty()
    {
        if (q_front == q_back)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
