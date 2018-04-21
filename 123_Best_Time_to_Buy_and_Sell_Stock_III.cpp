#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxProfit(vector<int>& prices) {
    int minBuyPrice1 = INT_MAX, minBuyPrice2 = INT_MAX;
    int maxProfit1 = 0, maxProfit2 = 0;
    if(prices.size() < 2) return 0;
    for(int value : prices){
        maxProfit2 = max(maxProfit2, value - minBuyPrice2);
        minBuyPrice2 = min(minBuyPrice2, value - maxProfit1);
        maxProfit1 = max(maxProfit1, value - minBuyPrice1);
        minBuyPrice1 = min(minBuyPrice1, value);
    }
    return maxProfit2;
}

int main(){
    return 0;
}