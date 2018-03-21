#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int triangleNumber(vector<int>& nums) {
    if(nums.size() < 3) return 0;
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i+1; j < nums.size() - 1; j++){
            int sum = nums[i] + nums[j];
            auto it = lower_bound(nums.begin() + j + 1, nums.end(),sum);
            // it points to the first element >= val
            ans += (int)(it - nums.begin())- j - 1;            
        }
    }
    return ans;
}
int main(){
    return 0;
}