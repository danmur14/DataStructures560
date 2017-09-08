/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.3.11
* @brief: Testing Prim v Kruskal
*/

#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include "MST.h"
#include "DS.h"

int main()
{
    double duration;
    Timer T;

    std::cout << "        |   Kruskal    |   Prim" << std::endl;
    int srandx = 0;
    for (int n = 1000; n <= 8000; n = n * 2)
    {
        int **random;
        std::cout << n;
        double kruskal[5], prim[5]; //hold times

        for (int i = 1; i < 2; i++) //5 seeds
        {
            srandx++;
            std::cout << srandx << " ";
            srand(srandx);         //set seed

            random = new int *[n]; //store random numbers
            for (int j = 0; j < n; j++)
            {
                random[j] = new int[n];
                for (int k = 0; k < n; k++)
                {
                    int x = rand() % 100;
                    int y;
                    if (x < 50)
                    {
                        y = 0;
                    }
                    else
                    {
                        y = rand() % (4 * n) + 1;
                    }

                    random[j][k] = y; //fill with random numbers
                }
            }

            MST M(n);
            M.build(random, n);

            //time kruskal
            T.start();
            M.kruskal();
            kruskal[i - 1] = T.stop();
            std::cout << "  |" << kruskal[i - 1];

            //time building primistHeap
            T.start();
            M.prim();
            prim[i - 1] = T.stop();
            std::cout << "   |" << prim[i - 1];
        }
        //calculate average
        double Ak = 0;
        double Ap = 0;
        for (int a = 0; a < 5; a++)
        {
            Ak += kruskal[a];
            Ap += prim[a];
        }
        Ak = Ak / 5.0;
        Ap = Ap / 5.0;
        std::cout << "AVG|" << Ak << "  |" << Ap << " ";
    }

    return (0);
}