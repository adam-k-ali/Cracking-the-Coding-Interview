#include <iostream>
#include <vector>

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

vector< vector<int> > rotate_matrix(vector< vector<int> > matrix) {
    int n = matrix.size();
    int layers = n / 2;
    for (int layer = 0; layer < layers; layer++) {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i];
            // left -> top
            matrix[first][i] = matrix[last-offset][first];
            // bottom -> left
            matrix[last-offset][first] = matrix[last][last-offset];
            // right -> bottom
            matrix[last][last-offset] = matrix[i][last];
            // top -> right
            matrix[i][last] = top;

        }
    }
    return matrix;
}

int run_tests() {
    vector< vector<int> > m1 = {{1, 2}, {3, 4}};
    m1 = rotate_matrix(m1);
    print_matrix(m1);

    vector< vector<int> > m2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    m2 = rotate_matrix(m2);
    print_matrix(m2);
    return 0;
}

int main() {
    return run_tests();
}