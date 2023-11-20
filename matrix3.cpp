#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {

    srand(time(NULL));
    const int rows = 10;
    const int columns = 12;

    int A[rows][columns];

    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < columns; ++k) {
            A[i][k] = rand();
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int k = 0; k < columns; ++k) {
            int rowsMin = *min_element(&A[i][0], &A[i][0] + columns);
            int columnsMax = *max_element(&A[0][k], &A[rows - 1][k] + 1);

            if (A[i][k] == rowsMin || A[i][k] == columnsMax) {
                cout << "Saddle point at (" << i << ", " << k << ") with value " << A[i][k] << endl;
            }
        }
    }

    return 0;
}
