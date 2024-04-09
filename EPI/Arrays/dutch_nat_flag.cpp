/*

    The Dutch NAtional Flag

*/


#include "../Lib/common.h"

void swap (int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void dutchSort(std::vector<int>& unsortedArray, int pivotIdx)
{
    int j = unsortedArray.size() , i = 0;
    int k = 0;
    int pivot = unsortedArray[pivotIdx];

    while(k < j)
    {
        if (unsortedArray[k] < pivot)
        {
            swap(&unsortedArray[i++], &unsortedArray[k++]);
        }
        else if (unsortedArray[k] == pivot)
        {
            k++;
        }
        else if (unsortedArray[k] > pivot)
        {
            swap(&unsortedArray[k], &unsortedArray[--j]);
        }
    }
}

int main()
{
    unsigned int retVal = 0;

    std::vector<int> unsortedArray = {1, 4, 2, 3, 4, 5, 7, 4, 3, 3, 3};
    dutchSort(unsortedArray, 3);

    for(int num:unsortedArray)
    {
        std::cout << num << " ";
    }

    return retVal;
}