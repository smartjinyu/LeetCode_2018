#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// This solution is in reference to the dicuss in LeetCode
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0) nums[index] *= -1;
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) ans.push_back(i+1);
    }
    return ans;
}
int main(){
    int myArray[] = {1,2,2,3,5,5,7};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    vector<int> ans = findDisappearedNumbers(nums);
    for(int num : ans) printf("%d ",num);
    return 0;
}
