#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <cmath>

using namespace std;

class IsingModel {
private:
    int L;
    vector<vector<int>> spins;
    double beta;
    mt19937 rng;
    uniform_real_distribution<double> dist;
    
    int getNeighborSum(int i, int j) {
        return spins[(i + 1) % L][j] + spins[(i - 1 + L) % L][j] +
               spins[i][(j + 1) % L] + spins[i][(j - 1 + L) % L];
    }
    
public:
    IsingModel(int size, double temperature) : L(size), beta(1.0 / temperature), rng(random_device{}()), dist(0.0, 1.0) {
        spins.resize(L, vector<int>(L, 1));
    }
    
    void metropolisStep() {
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                int x = rng() % L;
                int y = rng() % L;
                int dE = 2 * spins[x][y] * getNeighborSum(x, y);
                if (dE < 0 || dist(rng) < exp(-beta * dE)) {
                    spins[x][y] *= -1;
                }
            }
        }
    }
    
    double computeEnergy() {
        double E = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                E -= spins[i][j] * getNeighborSum(i, j) / 2.0;
            }
        }
        return E / (L * L);
    }
    
    double computeMagnetization() {
        double M = 0;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < L; j++) {
                M += spins[i][j];
            }
        }
        return M / (L * L);
    }
    
    void simulate(int steps, ofstream &file) {
        for (int i = 0; i < steps; i++) {
            metropolisStep();
            if (i % 100 == 0) { // Reduce noise by averaging over steps
                file << beta << " " << computeEnergy() << " " << computeMagnetization() << endl;
            }
        }
    }
};

int main() {
    int L = 20;
    int steps = 100000;
    ofstream file("ising_2d_data.txt");
    
    for (double T = 5.0; T >= 0.1; T -= 0.1) {
        IsingModel model(L, T);
        model.simulate(steps, file);
    }
    file.close();
    return 0;
}
