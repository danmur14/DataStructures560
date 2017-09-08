/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.5.3
* @brief: Starting Dijkstra's algorithm
*/

#include <iostream>
#include <fstream>
#include "Dijkstra.h"

int main()
{
    int number;

    //read file data.txt and insert
    std::ifstream data;
    data.open("data.txt");

    int tests;
    data >> tests;
    for (int i = 0; i < tests; i++)
    {
        int vertices;
        data >> vertices;

        int **graph = new int *[vertices];

        for (int j = 0; j < vertices; j++)
        {
            graph[j] = new int[vertices];

            for (int k = 0; k < vertices; k++)
            {
                data >> number;
                graph[j][k] = number;
            }
        }

        std::cout << "Output:" << std::endl;
        Dijkstra D (vertices);
        D.build(graph, vertices);
        D.solve();
    }

    return (0);
}