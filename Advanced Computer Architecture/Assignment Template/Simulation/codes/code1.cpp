#include <iostream>
#include <vector>

using namespace std;


int main() 
{
    // Example usage
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{7, 8, 9}, {10, 11, 12}, {13, 14, 15}};

    cout << "A is (" << A.size() << " x " << A[0].size() << ')' << " matrix" << endl;
    cout << "B is (" << B.size() << " x " << B[0].size() << ')' << " matrix" << endl << endl;
    
    return 0;
}
