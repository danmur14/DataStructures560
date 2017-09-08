/*
* @file: HashTable.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Defines methods for the HashTable
*/

#include "HashTable.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <stdexcept>

HashTable::HashTable(int prime, bool hashChoice)
{
    hashMethod = hashChoice;//true = quadratic, false = double hashing
    table = new Node<int>[prime];
    table_size = prime;
}

HashTable::~HashTable()
{
    int i = 0;
    while (i < table_size)
    {
        table[i].~Node();
        i++;
    }
    delete [] table;
}

int HashTable::hash(int value)
{
    int key;
    key = hash(value, 0);
    return(key);
}

int HashTable::hash(int value, int limit)
{
    int key;
    if(hashMethod){//quadratic
        if(limit != table_size){
            key = ((value % table_size) + (limit * limit)) % table_size;
            if(table[key].getValue() == -1) {
                return(key);
            } 
            else {
                limit++;
                hash(value, limit);
            }
        }
        else
        {
            return(-1);
        }
    }
    else//double hashing
    {
        if(limit != table_size){
            key = ((value % table_size) + limit * (5 - (value % 5))) % table_size;
            if(table[key].getValue() == -1) {
                return(key);
            } 
            else {
                limit++;
                hash(value, limit);
            }
        }
        else
        {
            return(-1);
        }
    }
    
}

bool HashTable::insert(int value) //insert
{
    if(find(value)) {
        return(false);
    }
    else {
        int key = hash(value); 
        if(key == -1) {
            return (false);
        }
        else {
            table[key].setValue(value);
            return(true);
        }
    }
}

bool HashTable::deletenode(int value)
{
    int key = find(value, 0);
    if(key == -1) {
        return(false);
    }
    else
    {
        table[key].setValue(-1);
        table[key].setFlag(true);
        return(true);
    }
}

bool HashTable::find(int value)
{
    int key = find(value, 0);
    if(key == -1) {
        return(false);
    }
    else {
        return(true);
    }
    
}

int HashTable::find(int value, int limit)
{
    int key;
    if(hashMethod){//quadratic
        if(limit != table_size){
            key = ((value % table_size) + limit*limit) % table_size;
            if(table[key].getValue() == value) {
                return(key);
            } 
            else if(!table[key].getFlag() && table[key].getValue() == -1){
                return(-1);
            }
            else {
                limit++;
                find(value, limit);
            }
        }
        else
        {
            return(-1);
        }
    }
    else {//double hashing
        if(limit != table_size){
            key = ((value % table_size) + limit * (5 - (value % 5))) % table_size;
            if(table[key].getValue() == value) {
                return(key);
            } 
            else if(!table[key].getFlag() && table[key].getValue() == -1){
                return(-1);
            }
            else {
                limit++;
                find(value, limit);
            }
        }
        else
        {
            return(-1);
        }
    }
}

void HashTable::print() const
{
    int i = 0;
    if(hashMethod) {
        std::cout << "Quadratic Probing" << std::endl;
    }
    else {
        std::cout << "Double Hashing" << std::endl;
    }
    while (i < table_size)
    {
        std::cout << i << ": " << table[i].getValue() << " flag = ";
        if(table[i].getFlag()){
            std::cout << "true" << std::endl;
        }
        else
        {
            std::cout << "false" << std::endl;
        } 
        i++;
    }
    return;
}
