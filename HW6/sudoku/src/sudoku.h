#include <iostream>
#include <cstring>

#define BOARD_SIZE 9
#define REGION_SIZE 3

class Sudoku {
private:
    int grid[9][9]{};

    // test if value is safe in column
    bool safeCol(int col, int val) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (grid[i][col] == val) {
                return false;
            }
        }
        return true;
    }

    // test if value is safe in row
    bool safeRow(int row, int val) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (grid[row][i] == val) {
                return false;
            }
        }
        return true;
    }

    // test if value is safe in region
    bool safeReg(int row, int col, int val) {
        // convert row and col to region
        int reg = REGION_SIZE * (row / REGION_SIZE) + (col / REGION_SIZE);

        // calculate first cell in region
        int regRow = reg / REGION_SIZE * REGION_SIZE;
        int regCol = reg % REGION_SIZE * REGION_SIZE;

        // checks region
        for (int i = 0; i < REGION_SIZE; i++) {
            for (int j = 0; j < REGION_SIZE; j++) {
                if (grid[regRow + i][regCol + j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    // finds empty spot
    // changes row and col due to pass-by-reference
    bool emptySpot(int &row, int &col) {
        for (row = 0; row < BOARD_SIZE; row++) {
            for (col = 0; col < BOARD_SIZE; col++) {
                if (grid[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%9][i/9] != otherGrid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
#ifdef PRINT
            printf("comparing grid(%d, %d)\n", i%9, i/9);
#endif
            if (grid[i%9][i/9] != other.grid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    bool solve() {
        // homework
        // https://www.youtube.com/watch?time_continue=191&v=l7f9-GNH1j8&feature=emb_logo
        // above link helped me
        int row = 0;
        int col = 0;

        // checks if board is full and properly solved
        if (!emptySpot(row, col)) {
            return true;
        }

        // tests different values
        for (int val = 1; val <= BOARD_SIZE; val++) {

            // checks if value works in specified space
            if (safeRow(row, val) && safeCol(col, val) && safeReg(row, col, val)) {
                grid[row][col] = val;

                if (solve()) {
                    return true;
                }

                // unassign cell for use in backtracking
                grid[row][col] = 0;
            }
        }
        // if no solution
        return false;
    }
};
