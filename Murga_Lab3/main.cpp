/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: The user interface
*/

#include "Node.h"
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

void printHashing()
{
    std::cout << "\n\nPlease choose one of the following hash methods:\n"
              << "1- quadratic\n"
              << "2- double hashing\n"
              << "3- exit\n";
}

int main()
{
    int choice;
    int value;
    int prime;
    int number;
    bool hashMethod;

    //read file data.txt and insert to table H
    std::ifstream data;
    data.open("data.txt");

    //table size
    data >> prime;

    //get hashing method
    do
    {
        printHashing();
        std::cin >> choice;
        switch (choice)
        {
        case 1: //quadratic
            hashMethod = true;
            choice = 3;
            break;
        case 2: //double hashing
            hashMethod = false;
            choice = 3;
            break;
        case 3:
            return(0); 
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 3);

    //create hash table
    HashTable H (prime, hashMethod);

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
            if(!(H.insert(value))){
                std::cout << "The number could not be inserted into the list." << std::endl;
            }
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
