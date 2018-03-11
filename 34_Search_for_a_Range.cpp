#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2,-1);
    if(nums.size() == 0){
        return ans;
    }
    int lo = 0 , hi = nums.size(), mid = 0;
    while(lo < hi){
        mid = (lo + hi)/2;
        target < nums[mid] ? hi = mid : lo = mid + 1;
    }
    int right = lo - 1;
    if(right < 0 || nums[right] != target){
        return ans;
    }
    lo = 0; hi = right;
    while(lo < hi){
        mid = (lo + hi)/2;
        target <= nums[mid] ? hi = mid : lo = mid + 1;
    }
    int left = lo;
    ans[0] = left; ans[1] = right;
    return ans;
}

int main(){
    int myArray[] = {1};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    vector<int> ans = searchRange(nums,0);
    printf("[%d,%d]\n",ans[0],ans[1]);
    return 0;
}