/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.11
* @brief: The user interface
*/

#include <iostream>
#include <fstream>
#include "MST.h"
#include "DS.h"

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

    int tests;
    data >> tests;
    for (int i = 0; i < tests; i++)
    {
        int vertices;
        data >> vertices;
        int graph[vertices * vertices];
        for (int j = 0; j < vertices * vertices; j++)
        {
            data >> number;
            graph[j] = number; 
        }

        MST M (vertices);
        M.build(graph, vertices * vertices);

        std::cout << "Graph" << i + 1 << ": " << std::endl;
        std::cout << "Kruskal: ";
        M.kruskal();
        std::cout << std::endl;
        std::cout << "Prim: ";
        M.prim();
        std::cout << std::endl;
    }

  return (0);
}