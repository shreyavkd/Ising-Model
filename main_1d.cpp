#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "isingmodel.h"
#include "monte_carlo_sim_1d.h"

int main(){
    const int size = 100;          // Number of spins in the 1D chain
    const double J = 1.0;          // Interaction energy
    const int steps = 100000;      // Monte Carlo steps per simulation
    const int num_configs = 100;   // Configurations to average over

    // Beta sweep parameters
    const double beta_min = 0.1;
    const double beta_max = 1.5;
    const double beta_step = 0.1;

    std::ofstream outfile("1D_simulation_results.csv");
    outfile << "Beta,Average Energy,Average Magnetisation\n";

    for (double beta = beta_min; beta <= beta_max + 1e-9; beta += beta_step) {
        double total_energy = 0.0;
        double total_mag = 0.0;
        for (int config = 0; config < num_configs; ++config) {
            IsingModel1D model(size, J);
            model.randomise_spins();
            Monte_Carlo_Sim_1D simulator(model, beta);
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
    std::cout << "\nResults written to '1D_simulation_results.csv'.\n";
    return 0;
}
