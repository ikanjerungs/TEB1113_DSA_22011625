/*********************
id: 22011625
name: Brooklyn Neo Allexius
contact: +60 19-7077 715
email: brooklyn_22011625@utp.edu.my
Lab: 2
*/
#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 100; // dont want the matrix too big
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Enter number of rows (max " << MAX_SIZE << "): ";
    cin >> rows;
    cout << "Enter number of columns (max " << MAX_SIZE << "): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_SIZE || cols <= 0 || cols > MAX_SIZE) {
        cerr << "Invalid matrix size." << endl;
        return 1;
    }

    cout << "Enter the matrix elements:\n"; //user input
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    cout << "Spiral order: [ ";
    while (top <= bottom && left <= right) {

        // left to right top row
        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }
        top++;

        // top to bottom right col
        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            
            // right to left bottom row
            for (int j = right; j >= left; j--) {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            
            // down to up left col
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << "]" << endl;

    return 0;
}