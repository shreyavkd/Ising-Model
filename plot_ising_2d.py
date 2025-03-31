import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("ising_2d_results.csv")

plt.plot(data, label="Magnetization")
plt.xlabel("Iterations")
plt.ylabel("Magnetization")
plt.legend()
plt.savefig("avg_magnetisation_vs_beta.png")
plt.show()
