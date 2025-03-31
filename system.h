#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include <random>

class System 
{
    private:
        double num_population;
        double J;
        std::vector<int> sites;

    public:
        System();
        System(int N); //default constructor - 1 dim
        System(int N, int M); //overloaded constructor - 2 dimensions

        int get_spin(int index);
        void set_spin(int index, int spin);

        double population_size(); //returns num_population

        double energy(); 

        double magnetisation();
};

#endif
