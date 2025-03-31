#include "isingmodel2d.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

IsingModel2D::IsingModel2D(int width, int height, double J)
{
    spins.resize(width, std::vector<int>(height));
    randomise_spins();
}

void IsingModel2D::randomise_spins()
{
    srand(time(0));
    
    for (int x = 0; x < width; x++) 
    {
        for (int y = 0; y < width; y++) 
        {
            spins[x][y] = rand() % 2;
            if (spins[x][y] == 0) spins[x][y] = -1;
        }
    }
}

int IsingModel2D::get_spin(int x, int y)
{
    return spins[x][y];
}

void IsingModel2D::set_spin(int x, int y, int spin) 
{
    spins[x][y] = spin;
}

void IsingModel2D::flip_spin(int x, int y)
{
    spins[x][y] = -1*spins[x][y];
}

double IsingModel2D::compute_energy()
{
    double energy = 0;
    for (int x = 0; x < width; x++) 
    {
        for (int y = 0; y < height; y++) 
        {
            int neighbour_1 = get_spin(periodicX(x+1), y);
            int neighbour_2 = get_spin(x, periodicY(y+1));

            energy += -J * spins[x][y] * (neighbour_1 + neighbour_2);
        }
    }
    return energy;
}

double IsingModel2D::compute_magnetisation()
{
    double magnetisation = 0;
    for (int x=0; x < width; x++)
    {
        for (int y=0; y<height; y++)
        {
            magnetisation += get_spin(x,y);
        }
    }
    return magnetisation;
}

double IsingModel2D::change_in_energy(int x, int y)
{
    int sum_neighbours= get_spin(periodicX(x-1), y) +
    get_spin(periodicX(x+1), y) +
    get_spin(x, periodicY(y - 1)) +
    get_spin(x, periodicY(y + 1));

    return -1 * J * get_spin(x,y) * sum_neighbours;
}

int IsingModel2D::periodicX(int x) const
{
    return (x+width) % width;
}

int IsingModel2D::periodicY(int y) const
{
    return (y + height) % height;
}
