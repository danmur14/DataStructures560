/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.26
* @brief: The user interface
*/

#include <iostream>
#include <fstream>
#include "SkewHeap.h"

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands for SkewHeap:\n"
              << "1- insert\n"
              << "2- deletemin\n"
              << "3- preorder\n"
              << "4- inorder\n"
              << "5- levelorder\n"
              << "6- exit\n";
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
    SkewHeap H (size);

    //insert values
    H.build(values, i);

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
            if(!(H.insert(value))){
                std::cout << "The number could not be inserted into the tree." << std::endl;
            }
            break;
        case 2: //deletemin
            if(!(H.deleteMin())){
                std::cout << "The minmax heap is empty." << std::endl;
            }
            break;
        case 3: //preorder
            H.preOrder();
            break;
        case 4: //inorder
            H.inOrder();
            break;
        case 5: //levelorder
            H.levelOrder();
            break;
        case 6: //exit
            break;
        default:
            choice = 0;
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 6);

  return (0);
}