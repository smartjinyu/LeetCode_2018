#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int mini = prices[0];
    int ans = 0;
    for(int i = 1; i < prices.size(); i++){
        mini = min(prices[i],mini);
        if(prices[i] - mini > 0){
            ans = max(ans,prices[i] - mini);
        }
    }
    return ans;
}
int main(){
    return 0;
}