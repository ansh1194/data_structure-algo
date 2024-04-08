/*

    Compute pow(x,y)

*/

#include "../Lib/common.h"

/*
    The function return the power of a floating number
*/

int computePow (double& num, int& power)
{
    double result = 0.0;
    long long y = power;

    if (power < 0)
    {
        power = -power;
        num = 1.0/num;
    }

    while (power)
    {
        if (power & 1)
        {
            result *= num;
        }
        num *= num;
        power >> 1;
    }
}

int main()
{

    double num = 4.212121;
    int power = 6;

    computePow(num, power);

    return 0;

}