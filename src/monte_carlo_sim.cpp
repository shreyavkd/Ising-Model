#include "monte_carlo_sim.h"
#include <cmath>
#include <cstdlib>

// Constructor initialises with model and inverse temperature
Monte_Carlo_Sim::Monte_Carlo_Sim(IsingModel1D& model, double beta)
    : model(model), beta(beta) {}

// Runs the Monte Carlo simulation using the Metropolis algorithm
void Monte_Carlo_Sim::run_simulation(int steps){
    int N = model.get_size();
    for(int i = 0; i < steps; ++i){
        // Selecting random spins
        int index = std::rand() % N;

        // Computing energy change if flipped
        double dE = model.change_in_energy(index);

        // Computing acceptance probability
        double P = std::exp(-beta * dE);

        // Accepting flip if energy decreases or with probability
        if(P >= 1.0 || ((double) std::rand() / RAND_MAX) < P){
            model.flip_spin(index);
        }
    }
}