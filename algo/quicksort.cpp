/*

    Quick Sort - Hoare Scheme Partioning

*/

#include <iostream>
#include <vector>

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(std::vector<int>& unsortedArray, int startIdx, int endIdx)
{
    int pivot = unsortedArray[startIdx + (endIdx - startIdx)/2];

    swap(&unsortedArray[startIdx+(endIdx - startIdx)/2], &unsortedArray[endIdx]);

    int i = startIdx -1;

    for (int j=startIdx; j<endIdx; j++)
    {
        if (unsortedArray[j]<pivot)
        {
            i++;
            swap(&unsortedArray[i], &unsortedArray[j]);
        }
    }

    swap(&unsortedArray[i+1], &unsortedArray[endIdx]);
    return i+1;
}

void quickSort(std::vector<int>& unsortedArray, int startIdx, int endIdx)
{
    if (startIdx < endIdx)
    {
        int pi = partition(unsortedArray, startIdx, endIdx);

        quickSort(unsortedArray, startIdx, pi-1);
        quickSort(unsortedArray, pi+1, endIdx);
    }
}

int main()
{
    std::vector<int> unsortedArray = {3,2,5,8,3,2,6,8};

    quickSort(unsortedArray, 0, unsortedArray.size()-1);

    for (int num:unsortedArray)
    {
        std::cout << num << "\n";
    }
}

 