#include "system.h"
#include <time.h>

System::System(int N) 
{
    this-> num_population = N;
    this-> J = 1;
    
    srand(time(0));

    for (int i = 0; i < num_population; i++)
    {
        int rand_spin = rand() % 1;
        if (rand_spin == 0) rand_spin = -1;
        set_spin(i, rand_spin);
    }
}

// System::System(int N, int M)
// {
//     this -> num_population = M;
    
//     for (int i=0; i < N; i++)
//     {
//         sites
//     }
// }

int System::get_spin(int index)
{
    if (index >= 0 && index <= num_population)
    {
        return sites[index];
    }
}

void System::set_spin(int index, int spin)
{
    if (index >= 0 && index <= num_population)
    {
        if (spin == 1 || spin == -1)
        { sites[index] = spin; }
    }
}

double System::energy()
{
    int total_energy = 0;
    for (int i = 0; i < num_population-1; i++)
    {
        total_energy += -J * sites[i] * sites[i+1];
    }
    
    return total_energy/num_population;
}

double System::magnetisation()
{
    int magnetisation = 0;
    for (int i = 0; i < num_population; i++)
    {
        magnetisation += sites[i];
    }
    return magnetisation/num_population;
}

