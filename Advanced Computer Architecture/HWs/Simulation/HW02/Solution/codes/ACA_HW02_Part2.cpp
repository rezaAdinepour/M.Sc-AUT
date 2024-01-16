//           ******************************************************
//          **   course         : Advanced Computer Architecture  **
//         ***   HomeWork       : 03                              ***
//        ****   Topic          : Simulation on gem5              ****
//        ****   AUTHOR         : Reza Adinepour                  ****
//         ***   Student ID:    : 402131055                       ***
//          **   Github         : github.com/rezaAdinepour/       **
//           ******************************************************



#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;


// Function to impleament random matrix
vector<vector<int>> random_number_gen(int row, int col, int lower_limit, int upper_limit) 
{
    srand(42);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(lower_limit, upper_limit);

    vector<vector<int>> matrix(row, vector<int>(col));

    for (auto& row : matrix) 
    {
        for (int& num : row) 
            num = dist(gen);
    }

    return matrix;
}


// Function to perform matrix multiplication
vector<vector<int>> matrix_mult(const vector<vector<int>>& A, const vector<vector<int>>& B)
{
    try 
    {
        int n = A.size();
        int m = B.size();
        int p = B[0].size();

        if (m != A[0].size()) 
            throw invalid_argument("The number of columns in matrix A must be equal to the number of rows in matrix B");

        // Set tile size
        int T = static_cast<int>(sqrt(m));

        // Create result matrix C
        vector<vector<int>> C(n, vector<int>(p, 0));

        for (int I = 0; I < n; I += T) 
        {
            for (int J = 0; J < p; J += T) 
            {
                for (int K = 0; K < m; K += T) 
                {
                    for (int i = I; i < min(I + T, n); i++) 
                    {
                        for (int j = J; j < min(J + T, p); j++) 
                        {
                            int sum_val = 0;
                            for (int k = K; k < min(K + T, m); k++) 
                                sum_val += A[i][k] * B[k][j];
                            C[i][j] += sum_val;
                        }
                    }
                }
            }
        }
        
        return C;
    }
    catch (const exception& e) 
    {
        return {{-1}};
    }
}

int main() 
{
    // Example usage
    int A_row = 150;
    int A_col = 150;

    int B_row = 150;
    int B_col = 200;

    int lowerLimit = -100;
    int upperLimit = 100;

    vector<vector<int>> A = random_number_gen(A_row, A_col, lowerLimit, upperLimit);
    vector<vector<int>> B = random_number_gen(B_row, B_col, lowerLimit, upperLimit);

    cout << "A is (" << A.size() << " x " << A[0].size() << ')' << " matrix" << endl;
    cout << "B is (" << B.size() << " x " << B[0].size() << ')' << " matrix" << endl;

    vector<vector<int>> result = matrix_mult(A, B);
    if (result[0][0] == -1)
        cout << "An error occurred." << endl;
    else 
    {
        cout << "A * B = " << endl;
        for (const auto& row : result) 
        {
            for (int elem : row) 
                cout << elem << " ";
            cout << endl;
        }
    }

    return 0;
}
