/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.11
* @brief: The user interface
*/

#include <iostream>
#include <fstream>
#include "BinomialQueue.h"

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands for BinomialQueue:\n"
              << "1- insert\n"
              << "2- deletemin\n"
              << "3- levelorder\n"
              << "4- exit\n";
}

int main()
{
    int choice;
    int value;
    int number;
    int size = 200;
    int values[size];

    //read file data.txt and insert to M
    std::ifstream data;
    data.open("data.txt");

    int i = 0;
    while (data >> number)
    {
        values[i] = number;
        i++;
    }

    //create M
    BinomialQueue B;

    //insert values
    B.build(values, i);

    //user interface to communicate with table B
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: //insert
            std::cout << "Choose a number to be inserted to the minmax heap:" << std::endl;
            std::cin >> value;
            if(!(B.insert(value))){
                std::cout << "The number could not be inserted into the tree." << std::endl;
            }
            break;
        case 2: //deletemin
            if(!(B.deleteMin())){
                std::cout << "The minmax heap is empty." << std::endl;
            }
            break;
        case 3: //levelorder
            B.levelOrder();
            break;
        case 4: //exit
            break;
        default:
            choice = 0;
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 4);

  return (0);
}