/*

    Increment an Arbitrary-Precision Interger

*/

#include "../Lib/common.h"

void incNumArr(std::vector<int>* numArr)
{
    bool carryFlag = false;
    int len = numArr->size()-1;
    for (int i = len; i>=0; i--)
    {
        if (carryFlag)
        {
            (*numArr)[i] += 1;
        }

        if (i == len)
        {
            (*numArr)[i] += 1;
        }
        if ((*numArr)[i] > 9)
        {
            carryFlag = true;
            (*numArr)[i] %= 10;
        }
        else
        {
            carryFlag = false;
        }
    }
    if (((*numArr)[0] == 0) && carryFlag)
        numArr->insert(numArr->begin(), 1);
}

int main()
{
    std::vector<int> numArr = {9,9,9};

    incNumArr(&numArr);

    for (int num:numArr)
    {
        std::cout << num << "\t";
    }
}