/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.11
* @brief: The user interface
*/

#include <iostream>
#include <fstream>
#include "MinMaxHeap.h"

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
              << "1- insert\n"
              << "2- deletemin\n"
              << "3- deletemax\n"
              << "4- levelorder\n"
              << "5- exit\n";
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
    MinMaxHeap M (size);

    //insert values
    M.build(values, i);

    //user interface to communicate with table H
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: //insert
            std::cout << "Choose a number to be inserted to the minmax heap:" << std::endl;
            std::cin >> value;
            if(!(M.insert(value))){
                std::cout << "The number could not be inserted into the tree." << std::endl;
            }
            break;
        case 2: //deletemin
            if(!(M.deleteMin())){
                std::cout << "The minmax heap is empty." << std::endl;
            }
            break;
        case 3: //deletemax
            if(!(M.deleteMax())){
                std::cout << "The minmax heap is empty." << std::endl;
            }
            break;
        case 4: //levelorder
            M.levelOrder();
            break;
        case 5: //exit
            break;
        default:
            choice = 0;
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 5);

  return (0);
}