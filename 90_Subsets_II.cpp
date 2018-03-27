#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
void subsetRec(vector<int>& nums, int begin, vector<int>& cur, vector<vector<int>>& ans){
    ans.push_back(cur);
    for(int i = begin; i < nums.size(); i++){
        if(i == begin || nums[i] != nums[i-1]){
            cur.push_back(nums[i]);
            subsetRec(nums,i+1,cur,ans);
            cur.pop_back();
        }
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.size() == 0) return ans;
    sort(nums.begin(),nums.end());
    vector<int> cur;
    subsetRec(nums,0,cur,ans);
    return ans;
}

int main(){
    return 0;
}