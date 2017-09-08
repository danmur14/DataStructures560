/*
* @file: HashTableQD.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: Defines methods for the HashTableQD
*/

#include "HashTableQD.h"
#include "NodeQD.h"
#include <iostream>
#include <string>

HashTableQD::HashTableQD(int prime, bool hashChoice)
{
    hashMethod = hashChoice;//true = quadratic, false = double hashing
    table = new NodeQD<int>[prime];
    table_size = prime;
}

HashTableQD::~HashTableQD()
{
    int i = 0;
    while (i < table_size)
    {
        table[i].~NodeQD();
        i++;
    }
    delete [] table;
}

int HashTableQD::hash(int value)
{
    int key;
    key = hash(value, 0);
    return(key);
}

int HashTableQD::hash(int value, int limit)
{
    int key;
    if(hashMethod){//quadratic
        if(limit != 60000){
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
        if(limit != 60000){
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

bool HashTableQD::insert(int value) //insert
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

bool HashTableQD::deletenode(int value)
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

bool HashTableQD::find(int value)
{
    int key = find(value, 0);
    if(key == -1) {
        return(false);
    }
    else {
        return(true);
    }
    
}

int HashTableQD::find(int value, int limit)
{
    int key;
    if(hashMethod){//quadratic
        if(limit != 60000){
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
        if(limit != 60000){
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

void HashTableQD::print() const
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
