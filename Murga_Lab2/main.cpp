/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: The user interface
*/

#include "DoubleLinkedList.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
              << "1- insert\n"
              << "2- delete\n"
              << "3- print\n"
              << "4- exit\n";
}

int main()
{
    int choice;
    int value;
    int prime;
    int number;

    //read file data.txt and insert to table H
    std::ifstream data;
    data.open("data.txt");

    //table sise
    data >> prime;
    HashTable H (prime);

    //insert values
    while(data) {
        data >> number;
        H.insert(number);
    }

    //user interface to communicate with table H
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: //insert
            std::cout << "Choose a number to be inserted to the hash table:" << std::endl;
            std::cin >> value;
            H.insert(value);
            break;
        case 2: //delete
            std::cout << "Choose a number to be removed from the hash table:" << std::endl;
            std::cin >> value;
            if(!(H.deletenode(value))){
                std::cout << "That number is not in the hash table." << std::endl;
            }
            break;
        case 3: //print
            H.print();
            break;
        case 4: //exit
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 4);

    //H.~HashTable();

    return (0);
}
