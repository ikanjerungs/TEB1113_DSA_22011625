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
    const int MAX_SIZE = 100; // dont want matrix too big
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

    
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    
    int k;
    cout << "Enter k: ";
    cin >> k;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int count = 0;
    int result = -1; //if k out of range

    while (top <= bottom && left <= right) {

        // from left to right top row
        for (int j = left; j <= right; ++j) {
            count++;
            if (count == k) {
                result = matrix[top][j];
                cout << "The " << k << "-th element in spiral order is: " << result << endl;
                return 0;
            }
        }
        top++;

        // from top to bottom on right column
        for (int i = top; i <= bottom; ++i) {
            count++;
            if (count == k) {
                result = matrix[i][right];
                cout << "The " << k << "-th element in spiral order is: " << result << endl;
                return 0;
            }
        }
        right--;

        // right to left on bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                count++;
                if (count == k) {
                    result = matrix[bottom][j];
                    cout << "The " << k << "-th element in spiral order is: " << result << endl;
                    return 0;
                }
            }
            bottom--;
        }

        // down to up on left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                count++;
                if (count == k) {
                    result = matrix[i][left];
                    cout << "The " << k << "-th element in spiral order is: " << result << endl;
                    return 0;
                }
            }
            left++;
        }
    }

    // If we reach here, k is out of range
    cerr << "k is out of range of the number of elements in the matrix." << endl;
    return 1;
}