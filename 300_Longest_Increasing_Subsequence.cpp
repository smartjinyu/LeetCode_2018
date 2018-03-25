#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int ans = 1;
    if(nums.size() <= 1) return nums.size();
    vector<int> dp(nums.size(),1);
    for(int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
                ans = max(ans,dp[i]);
            }
        }
    }
    return ans;
}
int main(){
    return 0;
}