#include <iostream>
#include <numeric>
#include <fstream> 
#include <iomanip>  //for decimal output
#include "isingmodel2D.h"
#include "monte_carlo_sim_2D.h"
#include <math.h>

using namespace std;

int main(){
    const int width = 100;          
    const int height = 100;         
    const double J = 1.0;           
    const double beta = 0.5;        
    const int steps = 1e5;      
    const int num_configs = 100;     
    
    // Beta sweep parameters
    const double beta_min = 0.1;
    const double beta_max = 1.5;
    const double beta_step = 0.1;

    // Output file for saving results
    std::ofstream outfile("ising_2d_results.csv");
    outfile << "Beta, Average Energy, Average Magnetisation\n";

    // Looping over beta values
    for(double beta = beta_min; beta <= beta_max + 1e-9; beta += beta_step){
        double total_energy = 0.0;
        double total_mag = 0.0;

        // Repeating simulation for each beta value to compute averages
        for(int config = 0; config < num_configs; ++config){
            // Creating a new Ising model with randomised spin configuration
            IsingModel2D model(width, height, J);
            model.randomise_spins();

            // Creating and running the Monte Carlo simulator
            Monte_Carlo_Sim_2D simulator(model, beta);
            simulator.run_simulation(steps);       

            // Accumulating for averaging later
            total_energy += model.compute_energy();
            total_mag += std::abs(model.compute_magnetisation());
        }

        // Computing averages for this beta
        double avg_E = total_energy / num_configs;
        double avg_M = total_mag / num_configs;

        // Printing out to terminal
        std::cout << std::fixed << std::setprecision(3);
        std::cout << "β = " << beta << " | Energy = " << avg_E << " | Magnetisation = " << avg_M << "\n";

        // Writing results to CSV
        outfile << beta << "," << avg_E << "," << avg_M << "\n";
    }

    // Closing the file after writing all the data
    outfile.close();
    std::cout << "\nResults written to 'ising_2d_results.csv'.\n";
    
    return 0;
}