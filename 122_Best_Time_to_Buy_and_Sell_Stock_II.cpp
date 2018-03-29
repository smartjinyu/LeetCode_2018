#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int ans = 0;
    if(prices.size() == 0) return 0;
    int lo = 0,  hi = 0;
    while(lo < prices.size() && hi < prices.size()){
        while (lo < prices.size() - 1 && prices[lo+1] < prices[lo]) lo++;
        if(lo == prices.size() - 1) break;
        hi = lo + 1;
        while (hi < prices.size() - 1 && prices[hi+1] > prices[hi]) hi++;
        ans += prices[hi] - prices[lo];
        lo = hi + 1;
    }
    return ans;
}
int main(){
    return 0;
}