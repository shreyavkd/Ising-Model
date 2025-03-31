#ifndef ISINGMODEL_H
#define ISINGMODEL_H

#include <vector>
#include <iostream>

class IsingModel1D 
{
private:
    int size;
    double J;
    std::vector<int> spins;
    int periodic(int i) const;

public:
    IsingModel1D(int size, double J=1);
    
    void randomise_spins();
    int get_spin(int index);
    void flip_spin(int index);

    int get_size();

    double compute_energy();
    double compute_magnetisation();

    double change_in_energy(int index);

    void print_config();
};

#endif
