#include "isingmodel.h"
#include <iostream>

int main() {
    IsingModel1D test(10, 1.0);
    test.save_to_file("test_ising.csv");

    std::cout << "Test case ran successfully.\n";
    return 0;
}
