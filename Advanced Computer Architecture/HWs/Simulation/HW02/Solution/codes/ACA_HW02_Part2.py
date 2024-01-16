#           ******************************************************
#          **   course         : Advanced Computer Architecture  **
#         ***   HomeWork       : 03                              ***
#        ****   Topic          : Simulation on gem5              ****
#        ****   AUTHOR         : Reza Adinepour                  ****
#         ***   Student ID:    : 402131055                       ***
#          **   Github         : github.com/rezaAdinepour/       **
#           ******************************************************


import numpy as np
import os
import random


# clear terminal, if you use windows, replace 'clear' with cls
clear = lambda: os.system('clear')
clear()



def matrix_mult(A, B):
    try:
        n = np.shape(A)[0]
        m = np.shape(B)[0]
        p = np.shape(B)[1]

        # checking the multiplicity condition
        if(m != np.shape(A)[1]):
            raise ValueError("The number of columns in matrix A must be equal to the number of rows in matrix B")

        # set tile size
        T = int(pow(m, 0.5))

        # create result matrix
        C = np.zeros((n, p))

        for I in range(0, n, T):
            for J in range(0, p, T):
                for K in range(0, m, T):
                    for i in range(I, min(I + T, n)):
                        for j in range(J, min(J + T, p)):
                            sum_val = 0
                            for k in range(K, min(K + T, m)):
                                sum_val += A[i][k] * B[k][j]
                            C[i][j] += sum_val

        return C
    except ValueError as e:
        return str(e)
    except Exception as e:
        return "An error occurred: " + str(e)


# Example usage
A_row = A_col = 150
B_row = 150
B_col = 200
lower_limit = -100
upper_limit = 100

random.seed(42)

# Create A_row*A_row random matrix, each of element between lower_limit to upper_limit
A = np.random.randint(lower_limit, upper_limit, size=(A_row, A_col))
B = np.random.randint(lower_limit, upper_limit, size=(B_row, B_col))

print('A is {} matrix'.format(np.shape(A)))
print('B is {} matrix\n'.format(np.shape(B)))

result = matrix_mult(A, B)
print('A * B = {}' .format(result))
