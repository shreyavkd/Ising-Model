#include <iostream>
#include <random>
#include "monte_carlo_sim.h"
#include <math.h>
#include <time.h>

using namespace std;

Monte_Carlo_Sim::Monte_Carlo_Sim(System s, double b)
{
    this-> system = s;
    this-> beta = b;
}

void Monte_Carlo_Sim::monte_carlo_step(int energy_change, int rand_choice_index)
{
    srand(time(0));

    double P = exp(-beta * energy_change);
    if (P>1) P = 1;

    float random_num = (float)rand() / (float)RAND_MAX;

    if (random_num < P)
    {
        int spin_old = system.get_spin(rand_choice_index);
        int spin_new = -1 * spin_old;
        system.set_spin(rand_choice_index, spin_new);
    }
}

void Monte_Carlo_Sim :: run_simulation(int num_iterations)
{
    for (int i=0; i < num_iterations; i++)
    {
        int max_index = system.population_size();
        int rand_choice_index = rand() % max_index;

        int energy_change = 0;

        //ensure circular chain - the following adjusts neighbours when index = 0 or n-1
        int neighbour_index_1 = (rand_choice_index -1 + max_index) % max_index;
        int neighbour_index_2 = (rand_choice_index +1 + max_index) % max_index;

        int energy_change_1 = -1 * (-J * system.get_spin(rand_choice_index) * system.get_spin(neighbour_index_1));
        int energy_change_2 = -1 * (-J * system.get_spin(rand_choice_index) * system.get_spin(neighbour_index_2));
        energy_change = energy_change_1 + energy_change_2;

        monte_carlo_step(energy_change, rand_choice_index);
    }
}

void Monte_Carlo_Sim::record_data(int energy, int magnetisation)
{
    energies.push_back(energy);
    magnetisations.push_back(magnetisation);
}

void Monte_Carlo_Sim::save(const std::string &filename)
{
    std::ofstream outFile(filename);
    for (int i=0; i < system.population_size(); i++)
    {
        outFile<< energies[i] << " " << magnetisations[i] << std::endl;
    }
    outFile.close()
}