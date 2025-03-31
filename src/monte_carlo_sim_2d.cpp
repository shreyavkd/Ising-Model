#include "Monte_Carlo_Sim_2D.h"
#include <cstdlib>
#include <cmath>

// Constructor: stores reference to the model and a beta value
Monte_Carlo_Sim_2D::Monte_Carlo_Sim_2D(IsingModel2D& model, double beta)
    : model(model), beta(beta){}

// Performing Metropolis updates over steps
void Monte_Carlo_Sim_2D::run_simulation(int steps){
    for(int i = 0; i < steps; ++i){
        int width = 100;
        int height = 100;

        // Selecting a random spin (x,y) in the grid
        int x = std::rand() % width;
        int y = std::rand() % height;

        // Computing the energy change if we selected spin is flipped
        double dE = model.change_in_energy(x,y);

        // Computing acceptance probability
        double P = std::exp(-beta * dE);

        // Accepting flip with probability P
        if(P >= 1.0 || ((double) std::rand() / RAND_MAX < P)){
            model.flip_spin(x, y);
        }
    }
}