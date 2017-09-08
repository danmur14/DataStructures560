/*
* @file: HashTable.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Defines methods for the HashTable
*/

#include "HashTable.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <string>
#include <stdexcept>

HashTable::HashTable(int prime)
{
    table = new DoubleLinkedList<int>[prime];
    table_size = prime;
}

HashTable::~HashTable()
{
    int i = 0;
    while (i < table_size)
    {
        table[i].~DoubleLinkedList();
        i++;
    }
    delete [] table;
}

int HashTable::hash(int value)
{
    return(value % table_size);
}

void HashTable::insert(int value) //insert
{
    int key;
    key = hash(value);
    if(!find(value)){
        table[key].insert(value);
    }
}

bool HashTable::deletenode(int value)
{
    int key;
    key = hash(value);
    if(table[key].remove(value)) {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool HashTable::find(int value)
{
    int key;
    key = hash(value);
    if(table[key].find(value) != nullptr) {
        return(true);
    }
    else
    {
        return(false);
    }
}

void HashTable::print() const
{
    int i = 0;
    while (i < table_size)
    {
        std::cout << i << ": ";
        table[i].printList();
        i++;
    }
    return;
}
