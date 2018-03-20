#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 3) return res;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size();){
        int target = -nums[i];
        if(target < 0) break;
        int lo = i + 1, hi = nums.size() - 1;
        while(lo < hi){
            int sum = nums[lo] + nums[hi];
            if(sum > target){
                hi--;
            }else if(sum < target){
                lo++;
            }else{
                vector<int> triple;
                triple.push_back(nums[i]); 
                triple.push_back(nums[lo]);
                triple.push_back(nums[hi]);
                res.push_back(triple);
                while(lo < hi && nums[lo] == triple[1]) lo++;
                while(lo < hi && nums[hi] == triple[2]) hi--;
            }
        }
        int temp = nums[i];
        while(i < nums.size() && nums[i] == temp) i++;       
    }
    return res;
}
int main(){
    return 0;
}