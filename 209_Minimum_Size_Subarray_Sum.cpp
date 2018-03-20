#include <iostream>
#include <vector>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0) return 0;
    vector<int> culSum(nums.size()+1,0);
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        culSum[i+1] = sum;
    }
    int lo = nums.size(), hi = nums.size();
    int ans = nums.size() + 1;
    while(lo >= 0){
        if(culSum[hi] - culSum[lo] < s){
            lo--;
        }else{
            ans = min(ans,hi-lo);
            hi--;
        }
    }
    if(ans == nums.size() + 1){
        return 0;
    }else{
        return ans;
    }
}
int main(){
    return 0;
}