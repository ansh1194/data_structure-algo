/*

    Delete Duplicates from sorted array

*/

#include "../Lib/common.h"

void delDups(std::vector<int>& numArr)
{
    int uniqueFindPtr = 0, nxtUniqueIdx = 1;

    while(uniqueFindPtr < numArr.size()-1)
    {
        if (numArr[uniqueFindPtr] == numArr[uniqueFindPtr+1])
        {
            uniqueFindPtr+=1;
        }
        else if (numArr[uniqueFindPtr] < numArr[uniqueFindPtr+1])
        {
            uniqueFindPtr+=1;
            numArr[nxtUniqueIdx] = numArr[uniqueFindPtr];
            nxtUniqueIdx+=1;
        }
    }

    while(nxtUniqueIdx<numArr.size())
    {
        numArr[nxtUniqueIdx++] = 0;
    }
}

int main(){

    std::vector<int> numArr = {1,2,5,5,7,9,9};
    delDups(numArr);

    // Print the modified array 
    for (auto num:numArr)
    {
        std::cout << num << "\t";
    }
}