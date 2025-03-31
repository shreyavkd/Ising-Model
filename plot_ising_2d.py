import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the 2D simulation CSV
data = pd.read_csv("ising_2d_results.csv")

plt.figure(figsize=(12, 8))
# Energy plot
plt.subplot(2, 1, 1)
plt.plot(data.iloc[:, 0], data.iloc[:, 1], 'o-', color='blue', label='Energy')
plt.xlabel('Beta')
plt.ylabel('Energy per spin')
plt.title('2D Ising Model: Energy vs Beta')
plt.legend()
plt.grid(True)

# Magnetisation plot
plt.subplot(2, 1, 2)
plt.plot(data.iloc[:, 0], data.iloc[:, 2], 'o-', color='red', label='Magnetisation')
plt.xlabel('Beta')
plt.ylabel('Magnetisation per spin')
plt.title('2D Ising Model: Magnetisation vs Beta')
plt.legend()
plt.grid(True)

plt.tight_layout()
plt.savefig("ising_2d_results.png")
plt.show()
