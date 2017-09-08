/*
* @file: HashTable.h
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Holds the public and private variables and methods of HashTable
*/

#ifndef HashTable_h
#define HashTable_h
#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>

class HashTable
{
public:
    HashTable(int prime, bool hashChoice);
    ~HashTable();
    bool insert(int value);
    bool deletenode(int value);
    bool find(int value);
    void print() const;

private:
    int hash(int value);
    int hash(int value, int limit);
    int find(int value, int limit);
    int table_size;
    Node<int> *table;
    bool hashMethod;//true = quadratic, false = double hashing
};


#endif