/*
* @file: Dijkstra.h
* @author: Daniel Murga
* @date: 2017.5.3
* @brief: Header file for Dijkstra.cpp
*/

#ifndef Dijkstra_h
#define Dijkstra_h

class Dijkstra
{
  public:
    Dijkstra(int vertices);
    void build(int **data, int size);
    void solve();

  private:
    int verts;
    int** graphAM;
    int *prev;
    int *dist;
    int *accepted;

};

#endif