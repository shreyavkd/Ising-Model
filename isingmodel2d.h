#ifndef ISINGMODEL2D_H
#define ISINGMODEL2D_H

#include <vector>
#include <iostream>

class IsingModel2D 
{
private:
    int width;
    int height;
    double J;
    std::vector<std::vector<int>> spins;
    int periodicX(int x) const;
    int periodicY(int y) const;

public:
    IsingModel2D(int width, int height, double J);
    void randomise_spins();
    int get_spin(int x, int y);
    void set_spin(int x, int y, int spin);
    void flip_spin(int x, int y);
    int get_width() const;
    int get_height() const;
    double compute_energy();
    double compute_magnetisation();
    double change_in_energy(int x, int y);
};

#endif
