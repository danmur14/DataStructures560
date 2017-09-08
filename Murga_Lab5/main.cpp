/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.1
* @brief: The user interface
*/

#include "BinarySearchTree.h"
#include <iostream>
#include <fstream>

void printMenu()
{
    std::cout << "\n\nPlease choose one of the following commands:\n"
              << "1- insert\n"
              << "2- remove\n"
              << "3- deletemin\n"
              << "4- deletemax\n"
              << "5- preorder\n"
              << "6- inorder\n"
              << "7- levelorder\n"
              << "8- exit\n";
}

int main()
{
    int choice;
    int value;
    int number;

    //read file data.txt and insert to BST
    std::ifstream data;
    data.open("data.txt");

    //create BST
    BinarySearchTree BST;

    //insert values
    while(data) {
        data >> number;
        BST.insert(number);
    }

    //user interface to communicate with table H
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1: //insert
            std::cout << "Choose a number to be inserted to the binary search tree:" << std::endl;
            std::cin >> value;
            if(!(BST.insert(value))){
                std::cout << "The number could not be inserted into the tree." << std::endl;
            }
            break;
        case 2: //remove
            std::cout << "Choose a number to be removed from the binary search tree:" << std::endl;
            std::cin >> value;
            if(!(BST.remove(value))){
                std::cout << "That number is not in the binary search tree." << std::endl;
            }
            break;
        case 3: //deletemin
            if(!(BST.deleteMin())){
                std::cout << "The binary search tree is empty." << std::endl;
            }
            break;
        case 4: //deletemax
            if(!(BST.deleteMax())){
                std::cout << "The binary search tree is empty." << std::endl;
            }
            break;
        case 5: //preorder
            BST.preOrder();
            break;
        case 6: //inorder
            BST.inOrder();
            break;
        case 7: //levelorder
            BST.levelOrder();
            break;
        case 8: //exit
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
        }
    } while (choice != 8);

  return (0);
}