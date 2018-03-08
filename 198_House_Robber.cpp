#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int res[1000] = {0};
int robRec(vector<int>& nums,int begin){
    if(res[begin] != -1){
        return res[begin];
    }else{
        int result = max(nums[begin] + robRec(nums,begin+2),nums[begin+1] + robRec(nums,begin+3));
        res[begin] = result;
        return result;
    }
}
int rob(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }else if(nums.size() == 1){
        return nums[0];
    }else if(nums.size() == 2){
        return max(nums[0],nums[1]);
    }else if(nums.size() == 3){
        return max(nums[0] + nums[2],nums[1]);
    }else{
        int n = nums.size() - 1;
        for(int i = 0; i < nums.size();i++){
            res[i] = -1;
        }
        res[n] = nums[n];
        res[n-1] = max(nums[n-1],nums[n]);
        res[n-2] = max(nums[n-2] + nums[n], nums[n-1]);
        return robRec(nums,0);
    }
}

int main(){
    int myArray[] = {1,5,3,7,8,2,5};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",rob(nums));
    return 0;
}