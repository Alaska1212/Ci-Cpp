#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> mat;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        mat.resize(r, vector<T>(c, T()));
    }

    Matrix(initializer_list<initializer_list<T>> list) {
        rows = list.size();
        cols = list.begin()->size();
        mat.resize(rows);
        size_t i = 0;
        for (const auto& row : list) {
            mat[i++] = row;
        }
    }

    vector<T>& operator[](size_t i) {
        return mat[i];
    }

    const vector<T>& operator[](size_t i) const {
        return mat[i];
    }

    size_t rowCount() const { return rows; }
    size_t colCount() const { return cols; }

    friend ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
        for (const auto& row : matrix.mat) {
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << endl;
        }
        return os;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            transform(mat[i].begin(), mat[i].end(), other.mat[i].begin(), result.mat[i].begin(), plus<T>());
        }
        return result;
    }

    vector<T> operator*(const vector<T>& vec) const {
        if (cols != vec.size()) {
            throw invalid_argument("Vector length must match the number of columns in the matrix.");
        }
        vector<T> result(rows, T());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i] += mat[i][j] * vec[j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Matrix dimensions must match for multiplication.");
        }
        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix<int> mat1 = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> mat2 = {{7, 8, 9}, {10, 11, 12}};
    vector<int> vec = {1, 2, 3};

    cout << "Matrix 1:\n" << mat1 << endl;
    cout << "Matrix 2:\n" << mat2 << endl;

    Matrix<int> sum = mat1 + mat2;
    cout << "Sum of matrices:\n" << sum << endl;

    vector<int> productVec = mat1 * vec;
    cout << "Product of matrix and vector:\n";
    for (int val : productVec) {
        cout << val << " ";
    }
    cout << endl;

    Matrix<int> productMat = mat1 * Matrix<int>({{1}, {2}, {3}});
    cout << "Product of matrices:\n" << productMat << endl;

    return 0;
}
