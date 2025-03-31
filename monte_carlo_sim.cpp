#include "monte_carlo_sim.h"
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

Monte_Carlo_Sim::Monte_Carlo_Sim(System &s, double b) : system(s)
{
    this-> beta = b;
}

void Monte_Carlo_Sim::monte_carlo_step()
{
    srand(time(0));
    int n = system.population_size();
    int J = system.get_J();

    int rand_choice_index = rand() % n;
    
    int current_spin = system.get_spin(rand_choice_index);
    int neighbour_index_1 = (rand_choice_index -1 + n) % n;
    int neighbour_index_2 = (rand_choice_index +1 + n) % n;

    int energy_change_1 = -1 * (-J * system.get_spin(rand_choice_index) * system.get_spin(neighbour_index_1));
    int energy_change_2 = -1 * (-J * system.get_spin(rand_choice_index) * system.get_spin(neighbour_index_2));
    int energy_change = energy_change_1 + energy_change_2;

    double P = exp(-beta * energy_change);
    if (P>1) P = 1;

    float random_num = (float)rand() / (float)RAND_MAX;

    if (random_num < P)
    {
        int spin_old = system.get_spin(rand_choice_index);
        int spin_new = -1 * spin_old;
        system.set_spin(rand_choice_index, spin_new);
    }

    std::cout << "Attempting flip at site " << rand_choice_index 
          << " with P = " << P << " and rand = " << random_num << std::endl;

}

void Monte_Carlo_Sim :: run_simulation(int num_iterations)
{
    for (int i=0; i < num_iterations; i++)
    {
        monte_carlo_step();
    }
}