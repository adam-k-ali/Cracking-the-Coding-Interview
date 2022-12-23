#include <iostream>
#include <vector>
#include <set>

using namespace std;

void print_matrix(vector< vector<int> > matrix) {
    printf("==================\n");
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("==================\n");
}

vector< vector<int> > zero_matrix(vector< vector<int> > matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    set<int> zeroRows;
    set<int> zeroCols;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                zeroRows.insert(i);
                zeroCols.insert(j);
            }
        }
    }
    for (int row : zeroRows) {
        for (int i = 0; i < n; i++) {
            matrix[row][i] = 0;
        }
    }
    for (int col : zeroCols) {
        for (int i = 0; i < m; i++) {
            matrix[i][col] = 0;
        }
    }
    return matrix;
}

int run_tests() {
    vector< vector<int> > m1 = {{1, 0}, {3, 4}};
    m1 = zero_matrix(m1);
    print_matrix(m1);

    vector< vector<int> > m2 = {{1,2,3,4}, {5,6,0,8}, {9,10,0,12}, {13,14,15,16}};
    m2 = zero_matrix(m2);
    print_matrix(m2);
    return 0;
}

int main() {
    return run_tests();
}