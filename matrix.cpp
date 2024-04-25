#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    int rows, cols;
    int **data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{};
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }
    
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}
    Matrix add(const Matrix &other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix &other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }
        return result;
    }
     void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

   
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    cout << "Enter matrix data:" << endl;
    m1.input();

    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    cout << "Enter matrix data:" << endl;
    m2.input();
    

    // Performing addition
    if (r1 == r2 && c1 == c2) {
        cout << "Result of Addition:" << endl;
        Matrix sum = m1.add(m2);
        sum.print();
    } else {
        cout << "Matrices cannot be added due to incompatible dimensions." << endl;
    }

    // Performing multiplication
    if (c1 == r2) {
        cout << "Result of Multiplication:" << endl;
        Matrix product = m1.multiply(m2);
        product.print();
    } else {
        cout << "Matrices cannot be multiplied due to incompatible dimensions." << endl;
    }

    // Transposing first matrix
    cout << "Transpose of the first matrix:" << endl;
    Matrix transpose1 = m1.transpose();
    transpose1.print();
    // Transposing second matrix
    cout << "Transpose of the second matrix:" << endl;
    Matrix transpose2 = m2.transpose();
    transpose2.print();

    return 0;
}