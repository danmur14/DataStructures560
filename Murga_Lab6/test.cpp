/*
* @file: test.cpp
* @author: Daniel Murga
* @date: 2017.3.5
* @brief: Timing between BST and MinHeap
*/

#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include "MinHeap.h"
#include "BinarySearchTree.h"

int main()
{
    double duration;
    Timer T;

    std::cout << "        |   BST    |   Heap" << std::endl;
    for (int n = 50000; n <= 400000; n = n * 2)
    {
        int random[n]; //store random numbers
        std::cout << n;
        double bst[5], hp[5], bstDI[5], hpDI[5]; //hold times
        for (int i = 1; i < 6; i++)
        {
            srand(i); //set seed
            for (int j = 0; j < n; j++)
            {
                random[j] = rand() % (4 * n) + 1; //fill with random numbers
            }

            //time building BST
            BinarySearchTree BST;
            T.start();
            for (int c = 0; c < n; c++)
            {
                BST.insert(random[c]);
            }
            bst[i - 1] = T.stop();
            std::cout << "  |" << bst[i - 1];

            //time building MinHeap
            MinHeap MH (2 * n);
            T.start();
            MH.build(random, n);
            hp[i - 1] = T.stop();
            std::cout << "   |" << hp[i - 1];

            //time deletion and insertion
            //create x operation array
            int op_size = .10 * n;
            int op[op_size];
            int op_y[op_size];
            for (int d = 0; d < op_size; d++)
            {
                op[d] = rand() % 100;  
                op_y[d] = rand() % (4 * n) + 1;  
            }

            std::cout << " |    Ops ";

            //time BST operations
            T.start();
            for (int e = 0; e < op_size; e++)
            {
                int x = op[e];
                if ((0 <= x) && (x < 10))
                {
                    BST.deleteMin();
                }
                else if ((10 <= x) && (x < 20))
                {
                    BST.deleteMax();
                }
                else if ((20 <= x) && (x < 50))
                {
                    int y = op_y[e];
                    BST.remove(y);
                }
                else if ((50 <= x) && (x < 100))
                {
                    int y = op_y[e];
                    BST.insert(y);
                }
            }
            bstDI[i - 1] = T.stop();
            std::cout << "   |" << bstDI[i - 1];

            //time MinHeap operations
            T.start();
            for (int f = 0; f < op_size; f++)
            {
                int x = op[f];
                if ((0 <= x) && (x < 10))
                {
                    MH.deleteMin();
                }
                else if ((10 <= x) && (x < 20))
                {
                    MH.deleteMax();
                }
                else if ((20 <= x) && (x < 50))
                {
                    int y = op_y[f];
                    MH.remove(y);
                }
                else if ((50 <= x) && (x < 100))
                {
                    int y = op_y[f];
                    MH.insert(y);
                }
            }
            hpDI[i - 1] = T.stop();
            std::cout << "   |" << hpDI[i - 1] << std::endl;
        }
        //calculate average
        double ABST = 0;
        double AMH = 0;
        double ABSTDI = 0;
        double AMHDI = 0;
        for (int a = 0; a < 5; a++)
        {
            ABST += bst[a];
            AMH += hp[a];
            ABSTDI += bstDI[a];
            AMHDI += hpDI[a];
        }
        ABST = ABST / 5.0;
        AMH = AMH / 5.0;
        ABSTDI = ABSTDI / 5.0;
        AMHDI = AMHDI / 5.0;
        std::cout << "AVG|" << ABST << "  |" << AMH << " ";
        std::cout << "OPAVG|" << ABSTDI << "  |" << AMHDI << std::endl;
    }

    return (0);
}
