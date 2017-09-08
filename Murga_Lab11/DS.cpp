/*
* @file: DisjointSet.cpp
* @author: Daniel Murga
* @date: 2017.4.16
* @brief: Implements data structure
*/

#include "DS.h"

DisjointSet::DisjointSet(int nSize)
{
    size = nSize;
    items = new DSI *[size];
    //add each vertix as set
    for (int i = 0; i < size; i++)
    {
        items[i] = new DSI(i);
        items[i]->rep = items[i];
    }
}

DSI *DisjointSet::Find(DSI *item)
{
    if (item->rep == item)
    {
        return item;
    }
    else
    {
        return Find(item->rep);
    }
}

int DisjointSet::Find(int val)
{
    return items[val]->rep->key;
}

void DisjointSet::Union(int x, int y)
{
    DSI *a = Find(items[x]);
    DSI *b = Find(items[y]);
    b->rep = a;
}