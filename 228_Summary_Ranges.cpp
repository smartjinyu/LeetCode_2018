#include <iostream>
#include <vector>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if(nums.size() == 0){
        return ans;
    }else if(nums.size() == 1){
        ans.push_back(to_string(nums[0]));
        return ans;
    }
    int begin = 0;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] - nums[i-1] != 1){
            if(i == begin + 1){
                ans.push_back(to_string(nums[begin]));
            }else{
                ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[i-1]));
            }
            begin = i;
        }
    }
    if(nums.size() == begin + 1){
        ans.push_back(to_string(nums[begin]));
    }else{
        ans.push_back(to_string(nums[begin]) + "->" + to_string(nums[nums.size() - 1]));
    }
    return ans;
}
int main(){
    return 0;
}