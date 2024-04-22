/*

    Sudoku Checker

*/

#include "../Lib/common.h"

bool validSudoku(std::vector<std::vector<char>>& sudoku)
{

    std::unordered_set<std::string> hashSet;

    for(int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            char currVal = sudoku[i][j];

            if (currVal != '.')
            {
                auto p1 = hashSet.insert("row"+std::to_string(i)+std::to_string(sudoku[i][j]));
                if (!p1.second)
                    return false;
                p1 = hashSet.insert("col"+std::to_string(j)+std::to_string(sudoku[i][j]));
                if (!p1.second)
                    return false;
                p1 = hashSet.insert("box"+std::to_string((i/3)*3 + (j/3))+std::to_string(sudoku[i][j]));
                if (!p1.second)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    std::vector<std::vector<char>> sudoku = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    
    std::cout << validSudoku(sudoku);

}