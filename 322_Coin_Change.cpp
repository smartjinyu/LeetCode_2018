#include <iostream>
#include <vector>
using namespace std;
int calNum(vector<int>& coins,vector<int>& dp, int n){
    if(n < 0){
        return -1;
    }else if(dp[n] != -2){
        return dp[n];
    }else{
        int ans = INT_MAX;
        for(int coin : coins){
            int res = calNum(coins,dp,n-coin);
            if(res != -1){
                ans = min(ans,1 + res);
            }
        }
        if(ans != INT_MAX){
            dp[n] = ans;
            return ans;
        }else{
            dp[n] = -1;
            return -1;
        }
    }
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,-2);
    dp[0] = 0;
    for(int num : coins){
        if(num < amount){
            dp[num] = 1;
        }
    }
    return calNum(coins,dp,amount);
}
int main(){
    return 0;
}