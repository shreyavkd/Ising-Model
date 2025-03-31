#include "monte_carlo_sim.h"
#include <cmath>
#include <cstdlib>

Monte_Carlo_Sim::Monte_Carlo_Sim(System &s, double b) : system(s), beta(b) {}

void Monte_Carlo_Sim::monte_carlo_step() {
    int index = rand() % system.population_size();
    
    int spin = system.get_spin(index);
    int left = system.get_spin((index - 1 + system.population_size()) % system.population_size());
    int right = system.get_spin((index + 1) % system.population_size());
    
    double deltaE = 2 * system.get_spin(index) * (left + right);

    if (deltaE <= 0 || (rand() / (double)RAND_MAX) < exp(-beta * deltaE)) {
        system.set_spin(index, -spin);
    }
}

void Monte_Carlo_Sim::run_simulation(int num_iterations) {
    for (int i = 0; i < num_iterations; i++) {
        monte_carlo_step();
    }
}
