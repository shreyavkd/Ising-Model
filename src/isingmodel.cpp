#include "isingmodel.h"
#include <random>
#include <cmath>
#include <iostream>

// Periodic boundary conditions
int IsingModel1D::periodic(int i) const {
    if (i < 0) return i + size;
    if (i >= size) return i - size;
    return i;
}

// Constructor
IsingModel1D::IsingModel1D(int size, double J) : size(size), J(J), spins(size, 1) {
    randomise_spins();
}

// Initialize with random spins
void IsingModel1D::randomise_spins() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for (int i = 0; i < size; i++) {
        spins[i] = 2 * dis(gen) - 1; // Maps 0 -> -1, 1 -> +1
    }
}

// Get a specific spin
int IsingModel1D::get_spin(int index) {
    return spins[periodic(index)];
}

// Flip a specific spin
void IsingModel1D::flip_spin(int index) {
    spins[index] *= -1;
}

// Get the size of the system
int IsingModel1D::get_size() {
    return size;
}

// Calculate the total energy
double IsingModel1D::compute_energy() {
    double energy = 0.0;
    for (int i = 0; i < size; i++) {
        energy -= J * spins[i] * spins[periodic(i + 1)];
    }
    return energy;
}

// Calculate the magnetisation
double IsingModel1D::compute_magnetisation() {
    double mag = 0.0;
    for (int i = 0; i < size; i++) {
        mag += spins[i];
    }
    return mag; // (Optionally normalize by dividing by size if desired)
}

// Calculate energy change when flipping a spin
double IsingModel1D::change_in_energy(int index) {
    return 2 * J * spins[index] * (spins[periodic(index - 1)] + spins[periodic(index + 1)]);
}

// Print the current configuration
void IsingModel1D::print_config() {
    for (int i = 0; i < size; i++) {
        std::cout << (spins[i] > 0 ? "+" : "-") << " ";
    }
    std::cout << std::endl;
}
