#ifndef MONTE_CARLO_SIM_1D_H
#define MONTE_CARLO_SIM_1D_H

#include "isingmodel.h"

class Monte_Carlo_Sim_1D
{
private:
    IsingModel1D &model;
    double beta;
public:
    Monte_Carlo_Sim_1D(IsingModel1D &m, double b);
    void monte_carlo_step();
    void run_simulation(int num_iterations);
};

#endif
