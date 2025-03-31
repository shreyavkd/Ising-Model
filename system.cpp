#include "system.h"
#include <time.h>
#include <fstream>

using namespace std;

System::System(int N, double J) 
{
    this-> num_population = N;
    this-> J = 1;
    
    srand(time(0));

    for (int i = 0; i < num_population; i++)
    {
        int rand_spin = rand() % 2; //generate random integer in [0,2) - so either 0 or 1
        if (rand_spin == 0) rand_spin = -1;
        set_spin(i, rand_spin);
    }
}

int System::get_spin(int index)
{
    if (index >= 0 && index < num_population)
    {
        return sites[index];
    }
}

void System::set_spin(int index, int spin)
{
    if (index >= 0 && index < num_population)
    {
        if (spin == 1 || spin == -1)
        { sites[index] = spin; }
    }
}

int System::get_J()
{
    return J;
}

double System::energy()
{
    double total_energy = 0;
    for (int i = 0; i < num_population; i++)
    {
        //preserving circular order, take modulus to ensure last site's neighbour is the first site
        int neighbour_index = (i+1) % num_population;
        total_energy += -J * sites[i] * sites[neighbour_index];
    }
    
    return total_energy;
}

double System::magnetisation()
{
    double magnetisation = 0;
    for (int i = 0; i < num_population; i++)
    {
        magnetisation += sites[i];
    }
    return magnetisation/num_population;
}

void System::save(const std::string &filename) const 
{
    std::ofstream outFile(filename);
    for (int i = 0; i < num_population; i++)
    {
        outFile << sites[i] << std::endl;
    }
    outFile.close();
}

