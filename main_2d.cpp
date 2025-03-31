#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "isingmodel2d.h"
#include "monte_carlo_sim_2d.h"

int main()
{
    const int width = 100;         
    const int height = 100;        
    const double J = 1.0;          
    const int steps = 1e5;        
    const int num_configs = 100;          // Beta sweep parameters
    const double beta_min = 0.1;
    const double beta_max = 1.5;
    const double beta_step = 0.1;

    std::ofstream outfile("ising_2d_results.csv");
    outfile << "Beta,Average Energy,Average Magnetisation\n";

    for (double beta = beta_min; beta <= beta_max + 1e-9; beta += beta_step) 
    {
        double total_energy = 0.0;
        double total_mag = 0.0;
        for (int config = 0; config < num_configs; config++) 
        {
            IsingModel2D model(width, height, J);
            model.randomise_spins();
            Monte_Carlo_Sim_2D simulator(model, beta);
            simulator.run_simulation(steps);
            total_energy += model.compute_energy();
            total_mag += std::abs(model.compute_magnetisation());
        }
        double avg_E = total_energy / num_configs;
        double avg_M = total_mag / num_configs;
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "β = " << beta << " | Energy = " << avg_E << " | Magnetisation = " << avg_M << "\n";
        outfile << beta << "," << avg_E << "," << avg_M << "\n";
    }
    outfile.close();
    std::cout << "\nResults written to 'ising_2d_results.csv'.\n";
    return 0;
}
