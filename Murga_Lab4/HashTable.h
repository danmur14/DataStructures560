/*
* @file: HashTable.h
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Holds the public and private variables and methods of HashTable
*/

#ifndef HashTable_h
#define HashTable_h
#include "DoubleLinkedList.h"
#include <iostream>
#include <string>
#include <stdexcept>

class HashTable
{
public:
    HashTable(int prime);
    ~HashTable();
    void insert(int value);
    bool deletenode(int value);
    bool find(int value);
    void print() const;

private:
    
    int hash(int value);
    int table_size;
    DoubleLinkedList<int> *table;
};


#endif