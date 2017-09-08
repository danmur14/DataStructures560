/*
* @file: Dijkstra.cpp
* @author: Daniel Murga
* @date: 2015.5.3
* @brief: Implements data structure
*/

#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(int vertices)
{
    verts = vertices;
}

void Dijkstra::build(int **data, int size)
{
    graphAM = data;
    prev = new int[verts];
    dist = new int[verts];
    accepted = new int[verts];

    for (int i = 0; i < verts; i++)
    {
        accepted[i] = 0; //no verts accepted yet
        dist[i] = graphAM[0][i]; //distance to verts from vert 0
        //if edge exists
        if (dist[i] != 0)
        {
            prev[i] = 1;
        }
        else
        {
            prev[i] = 0;
        }
    }
    accepted[0] = 1;
}

void Dijkstra::solve()
{
    int n = 1;
    while (n < verts)
    {
        int min = 999;
        int vert = 0;
        for (int i = 0; i < verts; i++) //find min dist
        {
            if (dist[i] < min && dist[i] != 0 && accepted[i] == 0) //min, edge exists, not already in set
            {
                min = dist[i];
                vert = i;
            }
        }

        accepted[vert] = 1; //union set to accepted

        for (int i = 0; i < verts; i++) //update dist
        {
            if ((dist[i] > dist[vert] + graphAM[vert][i] || dist[i] == 0) && graphAM[vert][i] != 0 && accepted[i] == 0) //new path is less than dist, edge exists, not accepted
            {
                dist[i] = dist[vert] + graphAM[vert][i]; //add dist to dist to prev vert
                prev[i] = vert; //add vert to prev
            }
        }
        n++; //added one vert
    }

    for (int i = 0; i < verts; i++) //print
    {
        std::cout << dist[i] << " "; 
    }
    std::cout << std::endl;

}