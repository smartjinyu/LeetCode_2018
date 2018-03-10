#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void permuteRec(vector<vector<int>>& res,vector<int>& nums, int begin){
    if(begin == nums.size()){
        res.push_back(nums);
    }else{
        for(int i = begin; i < nums.size(); i++){
            swap(nums[begin],nums[i]);
            permuteRec(res,nums,begin+1);
            swap(nums[begin],nums[i]);
        }

    }


}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    if(nums.size() < 2){
        res.push_back(nums);
        return res;
    }else{
        permuteRec(res,nums,0);
        return res;
    }
} 
int main(){
    int myArray[] = {1,2,3,4,5};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    vector<vector<int>> ans = permute(nums);
    for(vector<int> vec : ans){
        for(int res: vec){
            printf("%d ",res);
        }
        printf("\n");
    }
    return 0;
}