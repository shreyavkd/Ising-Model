#include "system.h"
#include "monte_carlo_sim.h"
#include <math.h>

int main()
{
    int num_of_sites = 100;
    System system_1d(num_of_sites);

    int num_iterations = pow(2,100);
    Monte_Carlo_Sim simulation_1d(system_1d, num_iterations, 1);

    simulation_1d.run_simulation();

    simulation_1d.record_data(system_1d.energy(), system_1d.magnetisation());

    return 1;
}