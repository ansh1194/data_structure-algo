/*

Computing the parity of the word

*/


#include "../Lib/common.h"

/*
    Remember : x & (x-1) => lower most bit cleared in x
    x & ~(x - 1) => gives the lower most bit
*/
int optimizedSol1(int &num)
{
    int parity = 0;

    while (num)
    {
        parity ^= 1;

        num &= num - 1;
    }

    return parity;
}

/*
    This solution works by the commutative and associative property of XOR
    i.e it does not matter what is the position or in which order we XOR 1
*/
int optimizedSol2(int &num)
{
    num ^= num >> 16;
    num ^= num >> 8;
    num ^= num >> 4;
    num ^= num >> 2;
    num ^= num >> 1;

    return num & 0x1;

}

int main()
{
    int num = 10;
    int parity = optimizedSol1(num);

    std::cout << "The parity of the given number with 1st Optimized Solution is : " << parity << std::endl;

    parity = optimizedSol2(num);

    std::cout << "The parity of the given number with 2nd Optimized Solution is : " << parity << std::endl;

    return 0;
}