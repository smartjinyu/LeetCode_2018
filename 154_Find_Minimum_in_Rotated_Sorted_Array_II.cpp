#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    int mid = 0;
    while(lo < hi){
        mid = (lo + hi)/2;
        if(nums[mid] > nums[hi]){
            lo = mid+1;
        }else if(nums[mid] < nums[hi]){
            hi = mid;
        }else{
            hi--;
        }
    }
    return nums[lo];
}
int main(){
    return 0;
}