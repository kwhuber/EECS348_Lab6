#include <iostream>
#include <fstream>
using namespace std;

const int MAX_SIZE = 100;

void read_file(int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int& matrix_size) {
	ifstream infile;
	string filename;
	cout << "\nEnter filename: ";
	cin >> filename;
	infile.open(filename);

	infile >> matrix_size;

	// Reads the contents from the file and stores it as matrix A.
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			infile >> matrixA[i][j];
		}
	}
	// Prints matrixA.
	cout << "\nMatrix A:" << endl;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << matrixA[i][j] << " ";
		}
		cout << endl;
	}

	// Reads the remaining contents from the file and stores it as matrix B.
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			infile >> matrixB[i][j];
		}
	}
	// Prints matrixB.
	cout << "\nMatrix B:" << endl;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << matrixB[i][j] << " ";
		}
		cout << endl;
	}
	infile.close();
}

//A function that adds two matricies. 
void add_matrices(const int matrix_size, int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE]) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			result[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}
	// Prints the sum of matrixA and matrixB.
	cout << "\nMatrix Sum (A + B):" << endl;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			// setw sets the width of each number so in this case, the output is 2 characters wide/long.
			cout << setw(2) << result[i][j] << " ";
		}
		cout << endl;
	}
}

// A function that subtracts two matricies.
void subtract_matrices(const int matrix_size, int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE]) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			result[i][j] = matrixA[i][j] - matrixB[i][j];
		}
	}
	// Prints the difference of matrixA and matrixB.
	cout << "\nMatrix Difference (A - B):" << endl;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}

// A function that multiplies two matricies. 
void multiply_matrices(const int matrix_size, int matrixA[][MAX_SIZE], int matrixB[][MAX_SIZE], int result[][MAX_SIZE]) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			result[i][j] = 0;
			for (int k = 0; k < matrix_size; k++) {
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	// Prints the product of matrixA and matrixB.
	cout << "\nMatrix Product (A * B):" << endl;
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			// setw sets the width of each number so in this case, the output is 3 characters wide/long.
			cout << setw(3) << result[i][j] << " ";
		}
		cout << endl;
	}
}

// Main function for cleaner organization.
int main() {
	cout << "\nKaden Huber\n";
	cout << "Lab#6: Matrix Manipulation\n";

	// Initializes matrix A, B, and the result with 100 rows and 100 columns.	
	int matrixA[MAX_SIZE][MAX_SIZE];
	int matrixB[MAX_SIZE][MAX_SIZE];
	int result[MAX_SIZE][MAX_SIZE];
	int matrix_size;

	read_file(matrixA, matrixB, matrix_size);
	add_matrices(matrix_size, matrixA, matrixB, result);
	multiply_matrices(matrix_size, matrixA, matrixB, result);
	subtract_matrices(matrix_size, matrixA, matrixB, result);
	cout << "\nProgram ended.\n\n";
}

