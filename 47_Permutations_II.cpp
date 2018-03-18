#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the dicuss in LeetCode
void permute(vector<int> nums, int begin, vector<vector<int>>& res){
    if(begin == nums.size() - 1){
        res.push_back(nums); return;
    }else{
        permute(nums,begin+1,res);
        for(int i = begin + 1; i < nums.size(); i++){
            if(nums[i] != nums[begin]){
                swap(nums[i],nums[begin]);
                permute(nums,begin+1,res);
            }
        }
    }
    
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> cur;
    if(nums.size() == 0) return res;
    sort(nums.begin(),nums.end());
    permute(nums,0,res);
    return res;
}
int main(){
    return 0;
}