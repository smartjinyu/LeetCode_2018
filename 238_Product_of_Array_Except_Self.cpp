#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    ans[0] = 1;
    for(int i = 1; i < nums.size(); i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    long long fromBack = 1;
    for(int i = nums.size() - 2; i >= 0; i--){
        fromBack *= nums[i+1];
        ans[i] *= fromBack;
    }
    return ans;
}

int main(){
    int myArray[] = {1,2,3,4,5};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    vector<int> res = productExceptSelf(nums);
    for(int i = 0; i < res.size(); i++){
        printf("%d\n",res[i]);
    }
    return 0;
}