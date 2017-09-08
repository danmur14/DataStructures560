/*
* @file: DisjointSet.h
* @author: Daniel Murga
* @date: 2017.4.16
* @brief: Header file for DisjointSet.cpp
*/

struct DSI
{
   int key; 
   DSI* rep = nullptr;

   DSI(int data)
   {
       key = data;
   }
};


class DisjointSet
{
  public:
    DisjointSet(int nSize);
    int Find(int val);
    void Union(int x, int y);

  private:
    int size;
    DSI** items;
    DSI* Find(DSI* node);

};