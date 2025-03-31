#include "isingmodel.h"
#include <iostream>
#include <fstream>

int main() {
    IsingModel1D test(10, 1.0);
    std::ofstream outfile("test_ising.csv");
    outfile << "Energy," << test.compute_energy() << std::endl;
    outfile << "Magnetisation," << test.compute_magnetisation() << std::endl;
    outfile.close();
    test.print_config();
    std::cout << "Test case ran successfully.\n";
    return 0;
}
