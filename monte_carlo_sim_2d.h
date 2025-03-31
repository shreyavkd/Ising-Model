#ifndef MONTE_CARLO_SIM_2D_H
#define MONTE_CARLO_SIM_2D_H

#include "isingmodel2d.h"

class Monte_Carlo_Sim_2D
{
private:
    IsingModel2D &model;
    double beta;
public:
    Monte_Carlo_Sim_2D(IsingModel2D &m, double b);
    void monte_carlo_step();
    void run_simulation(int num_iterations);
};

#endif
