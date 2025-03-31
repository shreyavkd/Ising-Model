import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# Load the data from the 1D simulation CSV
data = pd.read_csv("1D_simulation_results.csv")

# Plot Energy and Magnetisation vs Beta using the correct header names
plt.figure(figsize=(12, 6))
plt.plot(data['Beta'], data['Average Energy'], label='Energy', color='blue')
plt.plot(data['Beta'], data['Average Magnetisation'], label='Magnetisation', color='red')
plt.xlabel('Beta')
plt.ylabel('Values')
plt.title('1D Ising Model: Energy and Magnetisation vs Beta')
plt.legend()
plt.grid(True)
plt.show()
