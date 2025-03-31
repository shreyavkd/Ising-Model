#include "isingmodel2d.h"
#include <random>
#include <cmath>
#include <iostream>

// Periodic boundary conditions for x-coordinate
int IsingModel2D::periodicX(int x) const {
    if (x < 0) return x + width;
    if (x >= width) return x - width;
    return x;
}

// Periodic boundary conditions for y-coordinate
int IsingModel2D::periodicY(int y) const {
    if (y < 0) return y + height;
    if (y >= height) return y - height;
    return y;
}

// Constructor
IsingModel2D::IsingModel2D(int width, int height, double J) 
    : width(width), height(height), J(J), spins(height, std::vector<int>(width, 1)) {
    randomise_spins();
}

// Initialize with random spins
void IsingModel2D::randomise_spins() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            spins[y][x] = 2 * dis(gen) - 1;
        }
    }
}

// Get a specific spin
int IsingModel2D::get_spin(int x, int y) {
    return spins[periodicY(y)][periodicX(x)];
}

// Set a specific spin
void IsingModel2D::set_spin(int x, int y, int spin) {
    spins[periodicY(y)][periodicX(x)] = spin;
}

// Flip a specific spin
void IsingModel2D::flip_spin(int x, int y) {
    spins[periodicY(y)][periodicX(x)] *= -1;
}

// Get width
int IsingModel2D::get_width() const {
    return width;
}

// Get height
int IsingModel2D::get_height() const {
    return height;
}

// Calculate the total energy (avoiding double counting)
double IsingModel2D::compute_energy() {
    double energy = 0.0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Only count rightward and downward interactions
            if (x < width - 1)
                energy -= J * spins[y][x] * spins[y][x + 1];
            if (y < height - 1)
                energy -= J * spins[y][x] * spins[y + 1][x];
        }
    }
    return energy;
}

// Calculate the magnetisation
double IsingModel2D::compute_magnetisation() {
    double mag = 0.0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mag += spins[y][x];
        }
    }
    return mag / (width * height); // Normalized per spin
}

// Calculate energy change when flipping a spin
double IsingModel2D::change_in_energy(int x, int y) {
    return 2 * J * spins[y][x] * (
        spins[periodicY(y - 1)][periodicX(x)] + 
        spins[periodicY(y + 1)][periodicX(x)] + 
        spins[periodicY(y)][periodicX(x - 1)] + 
        spins[periodicY(y)][periodicX(x + 1)]
    );
}
