#ifndef MONTE_CARLO_SIM_H
#define MONTE_CARLO_SIM_H

#include "system.h"

using namespace std;

class Monte_Carlo_Sim
{
    private:
        System &system;
        double beta;

        // std::vector<int> energies;
        // std::vector<int> magnetisations;

    public:
        Monte_Carlo_Sim(System &s, double b);
        void monte_carlo_step();
        void run_simulation(int num_iterations);
};

#endif