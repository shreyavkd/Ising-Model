#include "system.h"
#include "monte_carlo_sim.h"
#include <iostream>
#include <fstream>
#include <time.h>

int main() {
    srand(time(0)); // Initialize random seed

    // ---------------------- 1D Ising Model ---------------------- //
    int num_sites = 100;
    double beta = 0.5;
    int num_iterations = 100000;

    System system_1d(num_sites);
    Monte_Carlo_Sim sim_1d(system_1d, beta);

    std::ofstream file1d("ising_1d_data.txt");
    for (int i = 0; i < num_iterations; i++) 
    {
        sim_1d.run_simulation(1); // Single MC step
        file1d << system_1d.energy() << " " << system_1d.magnetisation() << "\n";
    }
    file1d.close();
    std::cout << "1D simulation complete. Data saved to ising_1d_data.txt\n";
    return 0;

    system_1d.save("ising_output.txt");
    std::cout << "Simulation data saved to ising_output.txt" << std::endl;

}
