// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix in a neat grid
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                     int transposed[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], 
                 int matrixB[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE], 
                 int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE],
                      int matrixB[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE],
                      int rowsA, int colsA, int colsB) {
    // Initialize result matrix to 0
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int choice;
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    
    cout << "=== Matrix Operations ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Choose an operation (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "\n--- Transpose a Matrix ---" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        
        readMatrix(matrix1, rows, cols);
        
        cout << "\nOriginal Matrix:" << endl;
        displayMatrix(matrix1, rows, cols);
        
        transposeMatrix(matrix1, rows, cols, result);
        
        cout << "\nTransposed Matrix:" << endl;
        displayMatrix(result, cols, rows);  
        
    } else if (choice == 2) {

        cout << "\n--- Add Two Matrices ---" << endl;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        
        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matrix1, rows, cols);
        
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(matrix2, rows, cols);
        
        addMatrices(matrix1, matrix2, result, rows, cols);
        
        cout << "\nMatrix A:" << endl;
        displayMatrix(matrix1, rows, cols);
        
        cout << "\nMatrix B:" << endl;
        displayMatrix(matrix2, rows, cols);
        
        cout << "\nSum (A + B):" << endl;
        displayMatrix(result, rows, cols);
        
    } else if (choice == 3) {
        cout << "\n--- Multiply Two Matrices ---" << endl;
        int rowsA, colsA, rowsB, colsB;
        
        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;
        
        cout << "Enter rows for Matrix B (must equal columns of A): ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;
        
        if (colsA != rowsB) {
            cout << "Error: Columns of A must equal rows of B!" << endl;
            return 1;
        }
        
        cout << "\nEnter Matrix A:" << endl;
        readMatrix(matrix1, rowsA, colsA);
        
        cout << "\nEnter Matrix B:" << endl;
        readMatrix(matrix2, rowsB, colsB);
        
        multiplyMatrices(matrix1, matrix2, result, rowsA, colsA, colsB);
        
        cout << "\nMatrix A (" << rowsA << "x" << colsA << "):" << endl;
        displayMatrix(matrix1, rowsA, colsA);
        
        cout << "\nMatrix B (" << rowsB << "x" << colsB << "):" << endl;
        displayMatrix(matrix2, rowsB, colsB);
        
        cout << "\nProduct (A x B) (" << rowsA << "x" << colsB << "):" << endl;
        displayMatrix(result, rowsA, colsB);
        
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}