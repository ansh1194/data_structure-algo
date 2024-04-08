/*

    Reverse Digits

*/
#include "../Lib/common.h"

int reverseDigits(int& num)
{
    int result;
    bool negFlag = (num < 0) ? true:false;

    if (negFlag)
    {
        num = -num;
    }

    while (num)
    {
        result = result * 10 + num%10;
        num /= 10;
    }



    return negFlag ? -result:result;
}

int main()
{
    int num = 12234;

    std::cout << "Reverse digits are " << reverseDigits(num);
}