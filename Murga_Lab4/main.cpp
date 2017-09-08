/*
* @file: main.cpp
* @author: Daniel Murga
* @date: 2017.2.5
* @brief: The user interface
*/

#include "HashTable.h"
#include "HashTableQD.h"
#include <iostream>
#include <fstream>
#include "Timer.cpp"
#include <stdlib.h> 
#include <sys/time.h>

int main()
{
    int prime = 600011;
    double load;
    double duration;
    bool hashMethod;
    Timer T;

    std::cout << "  |   open    |   quad    |   double  |" << std::endl;
    for (load = 0.2; load < 0.9; load+= 0.1)
    {
        int size = 600011 * load; //size for each load factor
        int random[size]; //store random numbers
        std::cout << load;
        double opn[5], dbl[5], qd[5];
        for (int i = 1; i < 6; i++)
        {
            srand(i); //set seed
            for (int j = 0; j < size; j++)
            {
                random[j] = rand(); //fill with random numbers
            }
            //time open hashing
            HashTable Open (prime);
            T.start();
            for (int j = 0; j < size; j++)
            {
                Open.insert(random[j]);
            }
            opn[i - 1] = T.stop();
            std::cout << "  |" << opn[i - 1];

            //time closed quadratic probing
            HashTableQD Quad (prime, true);
            T.start();
            for (int j = 0; j < size; j++)
            {
                Quad.insert(random[j]);
            }
            dbl[i - 1] = T.stop();
            std::cout << "   |" << dbl[i - 1];

             //time closed double hashing
            HashTableQD Doub (prime, false);
            T.start();
            for (int j = 0; j < size; j++)
            {
                Doub.insert(random[j]);
            }
            qd[i - 1] = T.stop();
            std::cout << "  |" << qd[i - 1] << std::endl;
        }
        //calculate average
        double Aopen = 0;
        double Adouble = 0;
        double Aquad = 0;
        for (int a = 0; a < 5; a++)
        {
            Aopen += opn[a];
            Adouble += dbl[a];
            Aquad += qd[a];
        }
        Aopen = Aopen / 5.0;
        Adouble = Adouble / 5.0;
        Aquad = Aquad / 5.0;
        std::cout << "AVG|" << Aopen << "  |" << Adouble << "  |" << Aquad << std::endl;
    }

    return (0);
}
