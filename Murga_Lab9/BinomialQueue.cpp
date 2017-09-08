/*
* @file: BinomialQueue.cpp
* @author: Daniel Murga
* @date: 2015.3.26
* @brief: Implements data structure
*/

#include "BinomialQueue.h"

BinomialQueue::BinomialQueue()
{
    m_root = nullptr;
}

BinomialQueue::~BinomialQueue()
{
    delete m_root;
}

void BinomialQueue::build(int data[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insert(data[i]);
    }
}

bool BinomialQueue::insert(int value)
{
    Node *temp = new Node(value);
    temp->s_left = temp;
    m_root = merge(temp, m_root);
    return true;
}

//Q1 = new tree Q2 = root tree
Node *BinomialQueue::merge(Node *Q1, Node *Q2)
{
    if (Q2 == nullptr) //tree empty
    {
        return Q1;
    }
    else if (Q1 == nullptr) //new tree empty
    {
        return Q2;
    }
    else
    {
        int max = Q2->s_left->order > Q1->s_left->order ? Q2->s_left->order + 2 : Q1->s_left->order + 2;
        int i = 0;
        Node *BQ1[max]; //queue 1 added tree
        Node *place1 = Q1;
        Node *BQ2[max]; //queue 2 original tree
        Node *place2 = Q2;
        Node *C[max]; //carry
        //fill arrays
        for (i = 0; i < max; i++)
        {
            //fill first queue
            if (place1 != nullptr && place1->order == i)
            {
                BQ1[i] = place1;
                place1 = place1->s_right;
            }
            else
            {
                BQ1[i] = nullptr;
            }
            //fill second queue
            if (place2 != nullptr && place2->order == i)
            {
                BQ2[i] = place2;
                place2 = place2->s_right;
            }
            else
            {
                BQ2[i] = nullptr;
            }

            C[i] = nullptr;
        }

        //merge trees at each array location

        for (i = 0; i < max; i++)
        {
            if (BQ1[i] == nullptr && BQ2[i] == nullptr) //000 001
            {
                BQ2[i] = C[i];
            }
            else if (BQ1[i] == nullptr && BQ2[i] != nullptr) //01
            {
                if (C[i] != nullptr) //--1
                {
                    if (C[i]->key < BQ2[i]->key)
                    {
                        Node *t = BQ2[i];
                        BQ2[i] = C[i];
                        C[i] = t;
                    }

                    Node *temp = BQ2[i];
                    temp->order = temp->order + 1;
                    temp->s_right = nullptr;

                    BQ2[i] = nullptr;

                    temp->f_child->s_left->s_right = C[i];
                    C[i]->s_left = temp->f_child->s_left;
                    C[i]->s_right = nullptr;
                    temp->f_child->s_left = C[i];
                    C[i + 1] = temp;
                }
                else //010
                {
                    BQ2[i] = BQ2[i];
                }
            }
            else if (BQ1[i] != nullptr && BQ2[i] == nullptr) //10
            {
                if (C[i] != nullptr) //--1
                {
                    if (C[i]->key < BQ1[i]->key)
                    {
                        Node *t = BQ1[i];
                        BQ1[i] = C[i];
                        C[i] = t;
                    }

                    Node *temp = BQ1[i];
                    temp->order = temp->order + 1;
                    temp->s_right = nullptr;

                    temp->f_child->s_left->s_right = C[i];
                    C[i]->s_left = temp->f_child->s_left;
                    C[i]->s_right = nullptr;
                    temp->f_child->s_left = C[i];
                    C[i + 1] = temp;
                }
                else //--0
                {
                    BQ2[i] = BQ1[i];
                }
            }
            else
            {
                if (BQ1[i]->key < BQ2[i]->key) //110
                {
                    Node *temp = BQ2[i];
                    BQ2[i] = BQ1[i];
                    BQ1[i] = temp;
                }

                Node *temp = BQ2[i];           //smallest root
                temp->order = temp->order + 1; //add to order
                if (temp->f_child == nullptr)  //order 0
                {
                    temp->f_child = BQ1[i];
                    BQ1[i]->s_left = BQ1[i];
                    BQ1[i]->s_right = nullptr;
                    C[i + 1] = temp;
                }
                else
                {
                    temp->f_child->s_left->s_right = BQ1[i];
                    BQ1[i]->s_left = temp->f_child->s_left;
                    BQ1[i]->s_right = nullptr;
                    temp->f_child->s_left = BQ1[i];
                    C[i + 1] = temp;
                }

                BQ2[i] = nullptr;

                if (C[i] != nullptr) //111
                {
                    BQ2[i] = C[i];
                }
            }
        }

        // go through array and fix sibling links
        Node *mark = nullptr; 
        Node *root = nullptr;
        Node *next = nullptr;
        for (i = 0; i < max; i++)
        {
            next = BQ2[i];
            if (root == nullptr && BQ2[i] != nullptr)
            {
                root = BQ2[i];
                root->s_right = nullptr;
                root->s_left = root;
                mark = BQ2[i];
            }
            else if (next != nullptr)
            {
                mark->s_right = next;
                next->s_left = mark;
                root->s_left = next;
                mark = next;
            }
            else if (mark != nullptr && next == nullptr)
            {
                mark->s_right = nullptr;
            }
        }
        return root;
    }
}

bool BinomialQueue::deleteMin()
{
    //check if heap is empty
    if (m_root == nullptr)
    {
        return false;
    }

    Node *minN = m_root;
    Node *place = m_root;
    int min = place->key;
    while (place != nullptr) //find min location
    {
        if (place->key < min)
        {
            min = place->key;
            minN = place;
        }
        place = place->s_right;
    }

    if (minN == m_root) //delete first node
    {
        m_root = merge(m_root->f_child, m_root->s_right);
    }
    else //fix original tree
    {
        minN->s_left->s_right = minN->s_right;
        if(minN->s_right != nullptr)
        {
            minN->s_right->s_left = minN->s_left;
        }
        m_root = merge(minN->f_child, m_root); //merge children with root

    }
    delete minN;
    return true;
}

void BinomialQueue::levelOrder()
{
    Node *place = m_root;
    Queue Q;
    std::cout << std::endl;
    while (place != nullptr)
    {
        levelOrder(place);
        place = place->s_right;
        std::cout << "-----------------" << std::endl;
    }
}

void BinomialQueue::levelOrder(Node *cNode)
{
    Node *place = cNode->f_child;
    std::cout << cNode->key << "|" << cNode->order << std::endl;
    Queue F;
    int order = cNode->order; //B#
    while (place != nullptr)
    {
        std::cout << place->key << "|" << place->order << " ";
        if (place->f_child != nullptr)
        {
            F.Enqueue(place->f_child);
        }

        if (place->s_right != nullptr)
        {
            place = place->s_right;
        }
        else
        {
            if (place->order == order - 1) //\n at each line
            {
                std::cout << std::endl;
                order = place->order;
            }
            place = F.Dequeue();
        }
    }
}
