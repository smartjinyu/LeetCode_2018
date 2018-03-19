#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss of 3Sum
int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return abs(target);
    sort(nums.begin(),nums.end());
    int ans = nums[0]+nums[1]+nums[2];
    for(int i = 0; i < nums.size(); i++){
        int lo = i + 1, hi = nums.size() - 1;
        while(lo < hi){
            int sum = nums[i] + nums[lo] + nums[hi];
            if(sum < target){
                lo++;
                if(abs(sum - target) < abs(ans - target)) ans = sum;
            }else if(sum > target){
                hi--;
                if(abs(sum - target) < abs(ans - target)) ans = sum;
            }else{
                return target;
            }
        }
    }
    return ans;
}
int main(){
    return 0;
}