#include <iostream>
#include <vector>
using namespace std;
void addToSubset(vector<int> curAns, vector<vector<int>>& ans, int n, vector<int>& nums){
    // n is current index
    if(n == nums.size() - 1){
        ans.push_back(curAns);
        curAns.push_back(nums[n]);
        ans.push_back(curAns);
    } else {
        addToSubset(curAns,ans,n+1,nums);
        curAns.push_back(nums[n]);
        addToSubset(curAns,ans,n+1,nums);
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curAns;
    if(nums.size() == 0){
        return ans;
    } else if(nums.size() == 1){
        ans.push_back(curAns);
        curAns.push_back(nums[0]);
        ans.push_back(curAns);
        return ans;
    }
    addToSubset(curAns,ans,1,nums);
    curAns.push_back(nums[0]);
    addToSubset(curAns,ans,1,nums);
    return ans;
}

int main(){
    int myArray[] = {1,2,3};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    vector<vector<int>> res = subsets(nums);
    for(vector<int> vec : res){
        for(int num : vec){
            printf("%d ",num);
        }
        printf("\n");
    }
    return 0;
}