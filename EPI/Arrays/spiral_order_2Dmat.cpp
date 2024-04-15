/*

    Spiral Order of 2D matrix

*/

#include "../Lib/common.h"

void recuradd(std::vector<std::vector<int>>& inputMatrix,
                int offset,
                std::vector<int>* outputArray)
{
    // Recurse termination
    if(inputMatrix.size()-1 -offset == offset)
    {
        outputArray->push_back(inputMatrix[offset][offset]);
    }


    // n elements ->
    for(int i=offset; i<inputMatrix.size()-1 -offset; i++)
    {
        outputArray->push_back(inputMatrix[offset][i]);
    }

    // n-1 elements ->T
    for(int i=offset; i<inputMatrix.size()-1-offset; i++)
    {
        outputArray->push_back(inputMatrix[i][inputMatrix.size()-1 -offset]);
    }

    // n-1 elements <-
    for(int i=inputMatrix.size()-1 -offset; i>offset; i--)
    {
        outputArray->push_back(inputMatrix[inputMatrix.size()-1 -offset][i]);
    }

    // n-2 elements <-T
    for(int i=inputMatrix.size()-1 -offset; i>offset; i--)
    {
        outputArray->push_back(inputMatrix[i][offset]);
    }
}                

std::vector<int> spiralOrderCalc(std::vector<std::vector<int>>& inputMatrix)
{
    std::vector<int> retVec;

    for (int offset=0; offset< std::ceil(0.5* inputMatrix.size()); offset++)
    {
        recuradd(inputMatrix, offset, &retVec);
    }

    return std::move(retVec);
}

int main()
{
    std::vector<std::vector<int>> matrix =  {
                                            {1,2,3},
                                            {4,5,6},
                                            {7,8,9}
                                            };
    std::vector<int> spiralOrder = spiralOrderCalc(matrix);

    for (int num:spiralOrder)
    {
        std::cout<< num;
    }

}