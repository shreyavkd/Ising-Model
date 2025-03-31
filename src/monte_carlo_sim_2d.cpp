#include "monte_carlo_sim_2d.h"
#include <random>
#include <cmath>

Monte_Carlo_Sim_2D::Monte_Carlo_Sim_2D(IsingModel2D &m, double b) : model(m), beta(b) {}

void Monte_Carlo_Sim_2D::monte_carlo_step() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis_real(0.0, 1.0);
    int width = model.get_width();
    int height = model.get_height();
    std::uniform_int_distribution<> dis_x(0, width - 1);
    std::uniform_int_distribution<> dis_y(0, height - 1);
    int x = dis_x(gen);
    int y = dis_y(gen);
    double delta_E = model.change_in_energy(x, y);
    if (delta_E <= 0 || dis_real(gen) < exp(-beta * delta_E)) {
        model.flip_spin(x, y);
    }
}

void Monte_Carlo_Sim_2D::run_simulation(int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        monte_carlo_step();
    }
}
