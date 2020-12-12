//https://leetcode.com/problems/valid-sudoku/

namespace p36 {
    class Solution {
    public:
        bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
            // check row
            for (int row = 0; row < 9; ++row) {
                bool check[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                for (int col = 0; col < 9; ++col) {
                    if (board[row][col] != '.') {
                        int idx = (int)board[row][col] - 49;
                        if (check[idx] != 0) {
                            return false;
                        }
                        check[idx] = 1;
                    }

                }
            }

            // check col
            for (int col = 0; col < 9; ++col) {
                bool check[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                for (int row = 0; row < 9; ++row) {
                    if (board[row][col] != '.') {
                        int idx = (int)board[row][col] - 49;
                        if (check[idx] != 0) {
                            return false;
                        }
                        check[idx] = 1;
                    }

                }
            }
            // check square

            for (int row = 0; row < 9; row = row + 3) {
                for (int col = 0; col < 9; col = col + 3) {
                    bool check[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                    for (int ri = row; ri < row + 3; ++ri) {
                        for (int ci = col; ci < col + 3; ++ci) {
                            int idx = (int)board[ri][ci] - 49;
                            if (board[ri][ci] != '.') {
                                if (check[idx] != 0) {
                                    return false;
                                }
                                check[idx] = 1;
                            }
                        }
                    }

                }
            }

            return true;
        }
    };
}