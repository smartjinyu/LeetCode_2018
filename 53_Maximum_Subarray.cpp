#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        sum = max(sum,0);
        sum += nums[i];
        res = max(sum,res);
    }
    return res;
}
int main(){
    int myArray[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = vector<int>(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",maxSubArray(nums));
    return 0;
}