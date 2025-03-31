#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <random>

class System 
{
    private:
        int num_population;
        double J;
        std::vector<int> sites;

    public:
        System(int N, double J=1); //constructor - 1 dim

        int get_spin(int index);
        void set_spin(int index, int spin);

        int get_J();

        int population_size(); //returns num_population

        double energy(); 
        double magnetisation();

        void save(const std::string &filename) const;
};

#endif