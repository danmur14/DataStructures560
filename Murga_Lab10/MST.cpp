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

void MST::build(int data[], int size)
{
    //build adjacency matrix
    int i = 0;
    graphAM = new int *[verts];
    for (int j = 0; j < verts; j++)
    {
        graphAM[j] = new int[verts];
        for (int k = 0; k < verts; k++)
        {
            graphAM[j][k] = data[i];
            i++;
        }
    }
}

void MST::kruskal()
{
    int nEdges = 0;
    Edge *start = nullptr;
    Edge *loc = nullptr;
    //through adjacency matrix
    for (int j = 0; j < verts; j++)
    {
        for (int k = 0; k < verts; k++)
        {
            //upper triangle of array
            if (k > j && graphAM[j][k] != 0)
            {
                //bare bones of a pqueue using edges as nodes
                //beginning of pqueue
                if (start == nullptr)
                {
                    start = new Edge(j, k, graphAM[j][k]);
                    loc = start;
                    nEdges++;
                }
                else
                {
                    Edge *newE = new Edge(j, k, graphAM[j][k]);
                    loc = start;
                    //go through list
                    while (loc != nullptr)
                    {
                        //add before next edge
                        if (newE->cost < loc->cost)
                        {
                            //at head of list
                            if (loc == start)
                            {
                                loc->prev = newE;
                                newE->next = loc;
                                start = newE;
                                nEdges++;
                                break;
                            }
                            //middle
                            else
                            {
                                newE->prev = loc->prev;
                                loc->prev = newE;
                                newE->next = loc;
                                newE->prev->next = newE;
                                nEdges++;
                                break;
                            }
                        }
                        //not less than next edge
                        else
                        {
                            //end of list
                            if (loc->next == nullptr)
                            {
                                loc->next = newE;
                                newE->prev = loc;
                                nEdges++;
                                loc = nullptr;
                            }
                            //next edge
                            else
                            {
                                loc = loc->next;
                            }
                        }
                    }
                }
            }
        }
    }

    DisjointSet *ds = new DisjointSet(verts);
    Edge **spanE = new Edge *[verts - 1];
    int accepted = 0, i = 0;

    //get each edge and union if no cycle
    loc = start;
    while (accepted < verts - 1 && i < nEdges)
    {
        if (ds->Find(loc->oV) != ds->Find(loc->dV))
        {
            spanE[accepted] = loc;
            ds->Union(loc->oV, loc->dV);
            accepted++;
        }
        i++;
        loc = loc->next;
    }

    //print edges
    for (int i = 0; i < accepted; i++)
    {
        std::cout << "(" << spanE[i]->oV << ", " << spanE[i]->dV << ") ";
    }
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
        cost[i] = 999;
        chosen[i] = 0;
        origin[i] = 0;
    }

    //add vertex 0
    chosen[0] = 1;

    int x = 0;
    while (x < verts - 1)
    {
        int min = 999;
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

    for (int i = 0; i < accepted; i++)
    {
        std::cout << "(" << spanE[i]->oV << ", " << spanE[i]->dV << ") ";
    }
}
