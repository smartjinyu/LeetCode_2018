#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxProfit(int k, vector<int>& prices) {
    if(prices.size() < 2 || k < 1) return 0;
    if(k > prices.size()/2) k = prices.size()/2 + 1;
    vector<int> maxProfit(k,0); 
    vector<int> minBuyPrice(k, INT_MAX);
    for(int value : prices){
        for(int i = k - 1; i >= 1; i--){
            maxProfit[i] = max(maxProfit[i], value - minBuyPrice[i]);
            minBuyPrice[i] = min(minBuyPrice[i], value - maxProfit[i-1]);
        }
        maxProfit[0] = max(maxProfit[0], value - minBuyPrice[0]);
        minBuyPrice[0] = min(minBuyPrice[0], value);
    }
    return maxProfit[k-1];
}
int main(){
    return 0;
}