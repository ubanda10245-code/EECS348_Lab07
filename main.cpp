
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin(){
    // Loop through each row of the matrix
    for(int i = 0; i < SIZE; i++){
      // Loop through each column in the current row
      for(int j = 0; j < SIZE; j++){
        // Read an integer from standard input and store it in the index [i][j]
        cin >> data[i][j];
      }
    }
  }

  // 2. Display a matrix
  void display() const{
    // Loop through each row of the matrix
    for(int i = 0; i < SIZE; i++){
      // Loop through each column in the current row
      for(int j = 0; j < SIZE; j++){
        // Print the element at position [i][j] followed by a space
        cout << data[i][j] << " ";
      }
      // Print a newline after each row
      cout << endl;
    }
    // Print a newline for spacing
    cout << endl;
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const{
    // Create a new matrix to store the result
    Matrix result;
    // Loop through each row of the matrices
    for(int i = 0; i < SIZE; i++){
      // Loop through each column in the current row
      for(int j = 0; j < SIZE; j++){
        // Add corresponding elements and store in result
        result.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    // Return the result matrix
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const{
    // Create a new matrix to store the result
    Matrix result;
    // Loop through each row of the result matrix
    for(int i = 0; i < SIZE; i++){
      // Loop through each column of the result matrix
      for(int j = 0; j < SIZE; j++){
        // Initialize the result element at [i][j] to 0
        result.data[i][j] = 0;
        // Sum the products of corresponding elements
        for(int k = 0; k < SIZE; k++){
          // Store the value into the result element at [i][j]
          result.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    // Return the result matrix
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const{
    // Initialize sum to 0
    int sum = 0;
    // Loop through the diagonal elements (where row == column)
    for(int i = 0; i < SIZE; i++){
      // Add the diagonal element to the sum
      sum += data[i][i];
    }
    // Return the total sum
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2){
    // Loop through each column in the rows to be swapped
    for(int j = 0; j < SIZE; j++){
      // Store the value from row1 into temp
      int temp = data[row1][j];
      // Copy value from row2 to row1
      data[row1][j] = data[row2][j];
      // Copy the temporary value to row2
      data[row2][j] = temp;
    }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
