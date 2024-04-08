/*

    Decimal Integer Palindrome

*/

#include "../Lib/common.h"

bool isPalindrome(int& num)
{
    int numDigits = static_cast<int> (std::floor(log10(num))) + 1;
    int mask = static_cast<int> (std::pow(10, numDigits -1));
    
    
    for(int i = 0; i<(numDigits/2); i++)
    {
        if ((num/mask) != num%10)
            return false;
        num %= mask;
        num /= 10;
        mask /= 100;
    }

    return true;
}

int main()
{
    int num = 12233221;

    if (isPalindrome(num))
    {
        std::cout << "Number is palidrome";
    }
    else
    {
        std::cout << "Number is not a palidrome";
    }
}