// You are given a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:
// Each row must contain the digits 1-9 without duplicates.
// Each column must contain the digits 1-9 without duplicates.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.
// Return true if the Sudoku board is valid, otherwise return false
// Note: A board does not need to be full or be solvable to be valid.
// board[i][j] is a digit 1-9 or '.'.
// You should aim for a solution as good or better than O(n^2) time and O(n^2) space,
// where n is the number of rows in the square grid.
#include <vector>
#include <iostream>
#include <array>

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {

        // row check; t: O(n^2), s: O(1)
        for (int r = 0; r < 9; r++)
        {
            std::array<int, 10> vals = {};
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;
                int val = board[r][c] - '0';
                vals[val]++;
            }

            for (const int &v : vals)
            {
                if (v > 1)
                    return false;
            }
        }

        // column check; t: O(n^2), s: O(1)
        for (int c = 0; c < 9; c++)
        {
            std::array<int, 10> vals = {};
            for (int r = 0; r < 9; r++)
            {
                if (board[r][c] == '.')
                    continue;
                int val = board[r][c] - '0';
                vals[val]++;
            }

            for (const int &v : vals)
            {
                if (v > 1)
                    return false;
            }
        }

        // sub-box check: t: O(n^2), s: O(1)
        for (int boxRow = 0; boxRow < 3; boxRow++)
        {
            for (int boxCol = 0; boxCol < 3; boxCol++)
            {
                std::array<int, 10> vals = {};

                for (int innerRow = 0; innerRow < 3; innerRow++)
                {
                    for (int innerCol = 0; innerCol < 3; innerCol++)
                    {
                        int r = boxRow * 3 + innerRow;
                        int c = boxCol * 3 + innerCol;

                        if (board[r][c] == '.')
                            continue;
                        int val = board[r][c] - '0';
                        vals[val]++;
                    }
                }

                for (const int &v : vals)
                {
                    if (v > 1)
                        return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    std::vector<std::vector<char>> board = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution s;
    std::cout << s.isValidSudoku(board) << std::endl;


}