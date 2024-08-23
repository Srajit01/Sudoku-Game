#include <iostream>
using namespace std;

#define UNASSIGNED 0
#define N 9

void displayGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            cout << "\n---------+---------+---------";
        }
        cout << endl;
    }
}


bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || 
            grid[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}


bool isGridFull(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                return false;
            }
        }
    }
    return true;
}

void playSudoku(int grid[N][N]) {
    int row, col, num;
    while (!isGridFull(grid)) {
        displayGrid(grid);
        cout << "\nEnter row (1-9), column (1-9), and number (1-9) separated by spaces: ";
        cin >> row >> col >> num;

        row--;
        col--;

        if (row >= 0 && row < N && col >= 0 && col < N && num >= 1 && num <= 9) {
            if (grid[row][col] == UNASSIGNED) {
                if (isSafe(grid, row, col, num)) {
                    grid[row][col] = num;
                } else {
                    cout << "Invalid move. Try again." << endl;
                }
            } else {
                cout << "Cell already filled. Try another cell." << endl;
            }
        } else {
            cout << "Invalid input. Please enter values within the range." << endl;
        }
    }
    cout << "Congratulations! You've completed the Sudoku puzzle!" << endl;
    displayGrid(grid);
}

int main() {
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    playSudoku(grid);

    return 0;
}
