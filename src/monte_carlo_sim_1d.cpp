#include "monte_carlo_sim_1d.h"
#include <random>
#include <cmath>

Monte_Carlo_Sim_1D::Monte_Carlo_Sim_1D(IsingModel1D &m, double b) : model(m), beta(b) {}

void Monte_Carlo_Sim_1D::monte_carlo_step() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis_real(0.0, 1.0);
    int size = model.get_size();
    std::uniform_int_distribution<> dis(0, size - 1);
    int index = dis(gen);
    double delta_E = model.change_in_energy(index);
    if (delta_E <= 0 || dis_real(gen) < exp(-beta * delta_E)) {
        model.flip_spin(index);
    }
}

void Monte_Carlo_Sim_1D::run_simulation(int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        monte_carlo_step();
    }
}
