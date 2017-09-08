/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.1.29
* @brief: The user interface
*/

#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
              << "1- insert\n"
              << "2- delete\n"
              << "3- reverse\n"
              << "4- print\n"
              << "5- exit\n";
}

int main()
{
    int choice;
    int value;
    DoubleLinkedList<int> L;
    //read file data.txt and insert to DLL L
    std::ifstream data;
    int number;
    data.open("data.txt");
    while(data) {
        data >> number;
        L.insert(number);
    }

    //user interface to communicate with DLL
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: //insert
            std::cout << "Choose a number to be added to the list:" << std::endl;
            std::cin >> value;
            L.insert(value);
            break;
        case 2: //delete
            std::cout << "Choose a number to be deleted from the list:" << std::endl;
            std::cin >> value;
            if(!(L.remove(value))){
                std::cout << "That number is not in the list." << std::endl;
            }
            break;
        case 3: //reverse
            L.reverse();
            break;
        case 4: //print
            L.printList();
            break;
        case 5: //exit
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 5);

    L.~DoubleLinkedList();

    return (0);
}
