#include "isingmodel.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constructor: initialises model and randomises spins
IsingModel1D::IsingModel1D(int size, double J) : size(size), J(J), spins(size){
    std::srand(std::time(nullptr));
    randomise_spins();
}

// Randomly sets each spin to either +1 or -1
void IsingModel1D::randomise_spins(){
    for(int i = 0; i < size; ++i){
        spins[i] = (std::rand() % 2 == 0) ? 1 : -1;
    }
}

// Returns the spin at the given index
int IsingModel1D::get_spin(int index) 
{
    return spins[index];
}

// Flips the spin at the given index (+1 to -1, -1 to +1)
void IsingModel1D::flip_spin(int index)
{
    spins[index] *= -1;
}

// Returns the number of spins in the model
int IsingModel1D::get_size()
{
    return size;
}

// Computes the total interaction energy of the current configuration
// Only neighbours interact (i and i + 1) with periodic boundary
double IsingModel1D::compute_energy() 
{
    double energy = 0.0;
    for(int i = 0; i < size; ++i){
        int neighbour = periodic(i + 1);
        energy -= J * spins[i] * spins[neighbour];
    }
    return energy;
}

// Computes the net magnetisation (sum of all spin values)
double IsingModel1D::compute_magnetisation()
{
    int mag = 0;
    for(size_t i = 0; i < spins.size(); ++i){
        mag += spins[i];
    }
    return mag;
}

// Computes the energy change if spin at index is flipped
double IsingModel1D::change_in_energy(int index) 
{
    int left = spins[periodic(index - 1)];
    int right = spins[periodic(index + 1)];
    return 2.0 * J * spins[index] * (left + right);
}

// Prints out the spin configuration
void IsingModel1D::print_config()
{
    std::cout << "Spin Configuration:\n";
    for(int i = 0; i < size; ++i){
        if(spins[i] == +1){
            std::cout << "↑";
        } else{
            std::cout << "↓";
        }
    }
    std::cout << "\n";
}

// Wraps index around to implement periodic boundaries
int IsingModel1D::periodic(int i) const{
    return (i + size) % size;
}