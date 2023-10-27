import numpy as np


N = np.arange(9)
# print(N)
n_combinations = np.zeros(len(N))
# print(n_combinations)

for i in N:
    n_combinations[i] = ( (0.87) ** i ) * (1 - 0.87) ** (8 - i)

print(n_combinations)