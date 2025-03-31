#ifndef MONTE_CARLO_SIM_H
#define MONTE_CARLO_SIM_H

#include "isingmodel.h"

using namespace std;

class Monte_Carlo_Sim
{
    private:
        IsingModel1D &model;
        double beta;

    public:
        Monte_Carlo_Sim(IsingModel1D &model, double b);
        void monte_carlo_step(int N);
        void run_simulation(int num_iterations);
};

#endif