/*
* @file: test.cpp
* @author: Daniel Murga
* @date: 2017.3.5
* @brief: Timing between SkewHeap
*/

#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include "SkewHeap/SkewHeap.h"
#include "LeftistHeap/LeftistHeap.h"

int main()
{
    double duration;
    Timer T;

    std::cout << "        |   Leftist    |   Skew" << std::endl;
    for (int n = 50000; n <= 400000; n = n * 2)
    {
        int random[n]; //store random numbers
        std::cout << n;
        double skew[5], left[5], skewDI[5], leftDI[5]; //hold times
        for (int i = 1; i < 6; i++)
        {
            srand(i); //set seed
            for (int j = 0; j < n; j++)
            {
                random[j] = rand() % (4 * n) + 1; //fill with random numbers
            }

            //time building SkewHeap
            SkewHeap SH (n * 2);
            T.start();
            for (int c = 0; c < n; c++)
            {
                SH.insert(random[c]);
            }
            skew[i - 1] = T.stop();
            std::cout << "  |" << skew[i - 1];

            //time building LeftistHeap
            LeftistHeap LH (n * 2);
            T.start();
            for (int c = 0; c < n; c++)
            {
                LH.insert(random[c]);
            }
            left[i - 1] = T.stop();
            std::cout << "   |" << left[i - 1];

            //time deletion and insertion
            //create x operation array
            int op_size = .10 * n;
            int op[op_size]; //operation
            int op_y[op_size]; //integer to insert
            for (int d = 0; d < op_size; d++)
            {
                op[d] = rand() % 100;  
                op_y[d] = rand() % (4 * n) + 1;  
            }

            std::cout << " |    Ops ";

            //time SkewHeap operations
            T.start();
            for (int e = 0; e < op_size; e++)
            {
                int x = op[e];
                if ((0 <= x) && (x < 50))
                {
                    SH.deleteMin();
                }
                else 
                {
                    int y = op_y[e];
                    SH.insert(y);
                }
            }
            skewDI[i - 1] = T.stop();
            std::cout << "   |" << skewDI[i - 1];

            //time LeftistHeap operations
            T.start();
            for (int e = 0; e < op_size; e++)
            {
                int x = op[e];
                if ((0 <= x) && (x < 50))
                {
                    LH.deleteMin();
                }
                else 
                {
                    int y = op_y[e];
                    LH.insert(y);
                }
            }
            leftDI[i - 1] = T.stop();
            std::cout << "   |" << leftDI[i - 1] << std::endl;
        }
        //calculate average
        double ASH = 0;
        double ALH = 0;
        double ASHDI = 0;
        double ALHDI = 0;
        for (int a = 0; a < 5; a++)
        {
            ASH += skew[a];
            ALH += left[a];
            ASHDI += skewDI[a];
            ALHDI += leftDI[a];
        }
        ASH = ASH / 5.0;
        ALH = ALH / 5.0;
        ASHDI = ASHDI / 5.0;
        ALHDI = ALHDI / 5.0;
        std::cout << "AVG|" << ASH << "  |" << ALH << " ";
        std::cout << "OPAVG|" << ASHDI << "  |" << ALHDI << std::endl;
    }

    return (0);
}
