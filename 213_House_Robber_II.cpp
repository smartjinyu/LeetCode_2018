#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int robIt(vector<int>& nums, int lo, int hi){
    int prev = 0, cur = 0, temp = 0;
    for(int i = lo; i < hi; i++){
        temp = cur;
        cur = max(cur,prev + nums[i]);
        prev = temp;
    }
    return cur;
    
}
int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    return max(robIt(nums,0,nums.size()-1), robIt(nums,1,nums.size()));
}
int main(){
    return 0;
}