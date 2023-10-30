import numpy as np
import os

# clear terminal, if you use windows, replace 'clear' with cls
clear = lambda: os.system('clear')
clear()

# Example usage
A = np.array([[1, 2, 3], [4, 5, 6]])
B = np.array([[7, 8, 9], [9, 10, 11], [12, 13, 14]])

print('A is {} matrix'.format(np.shape(A)))
print('B is {} matrix\n'.format(np.shape(B)))

result = matrix_mult(A, B)
print('A * B = {}' .format(result))
