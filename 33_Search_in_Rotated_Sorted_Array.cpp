#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findPivot(vector<int>& nums){
    int first = nums[0];
    int lo = 0, hi = nums.size();
    int mid = 0;
    while(lo < hi){
        mid = (lo + hi)/2;
        if(nums[mid] < first){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    return --lo;
}
int binarySearch(vector<int>& nums, int lo, int hi, int target){
    // search in [lo, hi)
    int mid = 0;
    while(lo < hi){
        mid = (lo + hi)/2;
        target < nums[mid] ? hi = mid : lo = mid + 1;
    }
    return --lo;

}
int search(vector<int>& nums, int target) {
    if(nums.size() == 0){
        return -1;
    }
    int pivotIndex = findPivot(nums);
    int pivot = nums[pivotIndex];
    int first = nums[0];
    int index = 0;
    if(target > pivot){
        return -1;
    } else if(target >= first){
        index = binarySearch(nums,0,pivotIndex + 1,target);
    } else{
        index = binarySearch(nums,pivotIndex + 1,nums.size(),target);
    }
    return (nums[index] == target )? index : -1;
}

int main(){
    int myArray[] = {1,3};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",search(nums,1));
    return 0;
}