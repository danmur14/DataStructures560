/*
* @file: HashTableQD.h
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Holds the public and private variables and methods of HashTable
*/

#ifndef HashTableQD_h
#define HashTableQD_h
#include "NodeQD.h"
#include <iostream>
#include <string>
#include <stdexcept>

class HashTableQD
{
public:
    HashTableQD(int prime, bool hashChoice);
    ~HashTableQD();
    bool insert(int value);
    bool deletenode(int value);
    bool find(int value);
    void print() const;

private:
    int hash(int value);
    int hash(int value, int limit);
    int find(int value, int limit);
    int table_size;
    NodeQD<int> *table;
    bool hashMethod;//true = quadratic, false = double hashing
};


#endif