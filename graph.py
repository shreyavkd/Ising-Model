import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV file
filename = 'ising_2d_results.csv'
data = pd.read_csv(filename, delimiter='\t', skiprows=1)

# Rename columns to match the file's format
data.columns = ['Beta', 'Average Energy', 'Average Magnetisation']

# Plotting Average Energy vs Beta
plt.figure(figsize=(12, 5))

# Energy vs Beta
plt.subplot(1, 2, 1)
plt.plot(data['Beta'], data['Average Energy'], marker='o', color='b', label='Average Energy')
plt.xlabel('Beta')
plt.ylabel('Average Energy')
plt.title('Average Energy vs Beta')
plt.grid(True)
plt.legend()

# Magnetisation vs Beta
plt.subplot(1, 2, 2)
plt.plot(data['Beta'], data['Average Magnetisation'], marker='o', color='r', label='Average Magnetisation')
plt.xlabel('Beta')
plt.ylabel('Average Magnetisation')
plt.title('Average Magnetisation vs Beta')
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.show()
