#ifndef MONTE_CARLO_SIM_H
#define MONTE_CARLO_SIM_H

#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include "system.h"

using namespace std;

class Monte_Carlo_Sim
{
    private:
        System system;
        int J = 1;
        double beta;

        std::vector<int> energies;
        std::vector<int> magnetisations;

    public:
        Monte_Carlo_Sim(System s, double b);
        void monte_carlo_step(int energy_change, int rand_choice_index);
        void run_simulation(int num_iterations);
        void record_data(int energy, int magnetisation);
        void save(const std::string &filename);
};

#endif