#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i]-1 != i) return i+1;
    }
    return n+1;
}

int main(){
    int myArray[] = {1,1};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",firstMissingPositive(nums));
    return 0;
}