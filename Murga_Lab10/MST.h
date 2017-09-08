/*
* @file: MST.h
* @author: Daniel Murga
* @date: 2017.4.16
* @brief: Header file for MST.cpp
*/

#ifndef MST_h
#define MST_h

struct Edge
{
    int oV, dV, cost;
    Edge* next = nullptr;
    Edge* prev = nullptr;
    Edge(int source, int destination, int eCost)
    {
        oV = source;
        dV = destination;
        cost = eCost;
    }
};

class MST
{
  public:
    MST(int vertices);
    void build(int data[], int size);
    void kruskal();
    void prim();

  private:
    int verts;
    int** graphAM;
    int getMin(int cost[], int chosen[]);
};

#endif