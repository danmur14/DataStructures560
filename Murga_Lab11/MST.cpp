/*
* @file: MST.cpp
* @author: Daniel Murga
* @date: 2015.4.16
* @brief: Implements data structure
*/

#include "MST.h"
#include "DS.h"
#include <iostream>

MST::MST(int vertices)
{
    verts = vertices;
}

void MST::build(int **data, int size)
{
    //build adjacency matrix
    graphAM = data;
}

void MST::qSort(int left, int right, Edge **edgeArray)
{
    int i = left;
    int j = right;
    int pivot = edgeArray[(left + right) / 2]->cost;
    Edge *temp;

    while (i <= j)
    {
        while (edgeArray[i]->cost < pivot)
        {
            i++;
        }
        while (edgeArray[j]->cost > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = edgeArray[i];
            edgeArray[i] = edgeArray[j];
            edgeArray[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
    {
        qSort(left, j, edgeArray);
    }
    if (i < right)
    {
        qSort(i, right, edgeArray);
    }
}

void MST::kruskal()
{
    int nEdges = 0;
    Edge** edgeArray = new Edge*[(verts-1)*(verts-1)]; //array to use for quicksort
    Edge *loc = nullptr;
    //through adjacency matrix
    for (int j = 0; j < verts; j++)
    {
        for (int k = j + 1; k < verts; k++)
        {
            //upper triangle of array
            if (k > j && graphAM[j][k] != 0)
            {
                edgeArray[nEdges] = new Edge(j, k, graphAM[j][k]);
				nEdges++;
            }
        }
    }
    qSort(0, nEdges - 1, edgeArray); //new quicksort function instead of pqueue

    DisjointSet *ds = new DisjointSet(verts);
    Edge **spanE = new Edge *[verts - 1];
    int accepted = 0, i = 0;

    //get each edge and union if no cycle
    while (accepted < verts - 1 && i < nEdges)
    {
        loc = edgeArray[i];
        if (ds->Find(loc->oV) != ds->Find(loc->dV))
        {
            spanE[accepted] = loc;
            ds->Union(loc->oV, loc->dV);
            accepted++;
        }
        i++;
    }

    // //print edges
    // for (int i = 0; i < accepted; i++)
    // {
    //     std::cout << "(" << spanE[i]->oV << ", " << spanE[i]->dV << ") ";
    // }
}

void MST::prim()
{
    int cost[verts]; //hold cost to each vertex
    int chosen[verts];  //vertices that have been added
    int origin[verts]; //origin of cost
    int accepted = 0; //number of vertices accepted
    Edge **spanE = new Edge *[verts - 1];

    //initialize
    for (int i = 0; i < verts; i++)
    {
        cost[i] = 99999;
        chosen[i] = 0;
        origin[i] = 0;
    }

    //add vertex 0
    chosen[0] = 1;

    int x = 0;
    while (x < verts - 1)
    {
        int min = 99999;
        int minv = 0;
        //for each edge
        for (int i = 0; i < verts; i++)
        {
            //if part of set of edges
            if (chosen[i] == 1)
            {
                for (int j = 0; j < verts; j++)
                {
                    //check if minimum cost to not already added vertice
                    if (graphAM[i][j] <= cost[j] && graphAM[i][j] != 0 && chosen[j] != 1)
                    {
                        cost[j] = graphAM[i][j];
                        origin[j] = i;
                        //overall minimum edge
                        if (cost[j] < min)
                        {
                            min = cost[j];
                            minv = j;
                        }
                    }
                }
            }
        }

        //add edge
        chosen[minv] = 1;
        if (origin[minv] > minv)
        {
            spanE[accepted] = new Edge(minv, origin[minv], cost[minv]);
        }
        else
        {
            spanE[accepted] = new Edge(origin[minv], minv, cost[minv]);
        }
        accepted++;
        x++;
    }

    // for (int i = 0; i < accepted; i++)
    // {
    //     std::cout << "(" << spanE[i]->oV << ", " << spanE[i]->dV << ") ";
    // }
}
