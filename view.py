import numpy as np
import matplotlib.pyplot as plt

def plot_results(filename, title):
    data = np.loadtxt(filename)
    beta, energy, magnetization = data[:, 0], data[:, 1], data[:, 2]

    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.plot(beta, energy, '-o', label="Energy")
    plt.xlabel("Beta")
    plt.ylabel("Energy")
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.plot(beta, magnetization, '-o', label="Magnetization", color='r')
    plt.xlabel("Beta")
    plt.ylabel("Magnetization")
    plt.legend()
    
    plt.suptitle(title)
    plt.show()

plot_results("ising_1d_results.txt", "1D Ising Model")