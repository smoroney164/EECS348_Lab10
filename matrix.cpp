/* Name: Sydney Moroney
* Assignment: EECS 348 Lab 10
* Source: CHATGPT
* Purpose: This program takes in a file and will perform operations on it using operation overloading.
* These operations include addition, multiplication, sum of diagonal, swap rows and columns, and update element
* Date Created: 11/2/2026
* Input: Takes in a file with a number n for the NxN matrix and the matrix values
* Outputs: Prints all operations to terminal
* Collaborators: None besides CHATGPT
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    int n;
    vector<vector<long long>> data;

public:
    // Create an n x n matrix filled with zeros
    Matrix(int size) : n(size), data(size, vector<long long>(size, 0)) {}

    int size() const {
        return n;
    }

    // Practice 1: Read matrix values from the file
    bool read(istream& input) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!(input >> data[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    // Access and update individual elements
    long long get(int row, int col) const {
        return data[row][col];
    }

    void set(int row, int col, long long value) {
        data[row][col] = value;
    }

    // Display the matrix with aligned columns
    void display() const {
        int width = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int digits = static_cast<int>(
                    to_string(data[i][j]).length()
                );
                if (digits > width) {
                    width = digits;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << setw(width + 2) << data[i][j];
            }
            cout << '\n';
        }
    }

    // Practice 2: Matrix addition using operator overloading
    Matrix operator+(const Matrix& other) const {
        if (n != other.n) {
            throw invalid_argument("Matrix sizes must match.");
        }

        Matrix result(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result.data[i][j] =
                    data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // Practice 3: Matrix multiplication using operator overloading
    Matrix operator*(const Matrix& other) const {
        if (n != other.n) {
            throw invalid_argument("Matrix sizes must match.");
        }

        Matrix result(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.data[i][j] +=
                        data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    // Practice 4: Sum of the main diagonal
    long long mainDiagonalSum() const {
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += data[i][i];
        }

        return sum;
    }

    // Practice 4: Sum of the secondary diagonal
    long long secondaryDiagonalSum() const {
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += data[i][n - 1 - i];
        }

        return sum;
    }
};

// Practice 5: Swap two rows
// Passing Matrix by value preserves the original
void swapRows(Matrix matrix, int row1 = 0, int row2 = 1) {
    int n = matrix.size();

    if (row1 < 0 || row2 < 0 || row1 >= n || row2 >= n) {
        cout << "Invalid row indices.\n";
        return;
    }

    for (int j = 0; j < n; j++) {
        long long temp = matrix.get(row1, j);
        matrix.set(row1, j, matrix.get(row2, j));
        matrix.set(row2, j, temp);
    }

    matrix.display();
}

// Practice 6: Swap two columns
void swapColumns(Matrix matrix, int col1 = 0, int col2 = 1) {
    int n = matrix.size();

    if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) {
        cout << "Invalid column indices.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        long long temp = matrix.get(i, col1);
        matrix.set(i, col1, matrix.get(i, col2));
        matrix.set(i, col2, temp);
    }

    matrix.display();
}

// Practice 7: Update a matrix element
// Default position is (0,0), default value is 100
void updateElement(Matrix matrix, int row = 0,
                   int col = 0, long long value = 100) {
    int n = matrix.size();

    if (row < 0 || col < 0 || row >= n || col >= n) {
        cout << "Invalid row or column index.\n";
        return;
    }

    matrix.set(row, col, value);
    matrix.display();
}

int main() {
    string filename;

    cout << "Enter input filename: ";
    cin >> filename;

    ifstream input(filename);

    if (!input) {
        cout << "Error: Could not open " << filename << ".\n";
        return 1;
    }

    int n;

    if (!(input >> n) || n <= 0) {
        cout << "Error: Invalid matrix size.\n";
        return 1;
    }

    Matrix A(n), B(n);

    if (!A.read(input) || !B.read(input)) {
        cout << "Error: File does not contain two complete matrices.\n";
        return 1;
    }

    // Practice 1
    cout << "\nPractice 1 - Matrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    // Practice 2
    cout << "\nPractice 2 - A + B:\n";
    Matrix sum = A + B;
    sum.display();

    // Practice 3
    cout << "\nPractice 3 - A * B:\n";
    Matrix product = A * B;
    product.display();

    // Practice 4
    cout << "\nPractice 4 - Diagonal sums:\n";
    cout << "A: main = " << A.mainDiagonalSum()
         << ", secondary = " << A.secondaryDiagonalSum() << '\n';

    cout << "B: main = " << B.mainDiagonalSum()
         << ", secondary = " << B.secondaryDiagonalSum() << '\n';

    // Practice 5
    cout << "\nPractice 5 - Swap rows 0 and 1 in A:\n";
    swapRows(A);

    // Practice 6
    cout << "\nPractice 6 - Swap columns 0 and 1 in A:\n";
    swapColumns(A);

    // Practice 7
    cout << "\nPractice 7 - Set A[0][0] = 100:\n";
    updateElement(A);

    // Allow custom indices and values
    char choice;

    cout << "\nWould you like to try custom swaps/updates? (y/n): ";

    if (cin >> choice && (choice == 'y' || choice == 'Y')) {
        int first, second;

        cout << "Enter two row indices to swap (0 to "
             << n - 1 << "): ";
        if (!(cin >> first >> second)) return 1;
        swapRows(A, first, second);

        cout << "Enter two column indices to swap (0 to "
             << n - 1 << "): ";
        if (!(cin >> first >> second)) return 1;
        swapColumns(A, first, second);

        int row, col;
        long long value;

        cout << "Enter row, column, and new value: ";
        if (!(cin >> row >> col >> value)) return 1;
        updateElement(A, row, col, value);
    }

    // Confirm original matrix was not modified
    cout << "\nOriginal Matrix A (unchanged):\n";
    A.display();

    return 0;
}