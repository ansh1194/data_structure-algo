/*

    Buy and Sell a Stock 

*/

#include "../Lib/common.h"

int calcMaxProfit(std::vector<int> &stockPrice)
{
    int maxProfit = 0;
    int minPrice = std::numeric_limits<int>::max();

    for (int price : stockPrice)
    {
        int maxProfitToday = price - minPrice;
        maxProfit = std::max(maxProfit, maxProfitToday);
        minPrice = std::min(price, minPrice);

    }

    return maxProfit;
}

int main()
{

    std::vector<int> stockPrice = {310,315,275,295,260,270,290,230,255,250};

    int maxProfit = calcMaxProfit(stockPrice);

    std::cout << maxProfit << "\n";

}