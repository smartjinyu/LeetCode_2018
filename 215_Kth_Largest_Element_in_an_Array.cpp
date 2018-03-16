#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int partition(vector<int>& nums, int lo, int hi){
    // [lo,hi]
    swap(nums[lo],nums[lo+rand()%(hi-lo+1)]);
    int pivot = nums[lo];
    while(lo < hi){
        while(lo < hi){
            if(nums[hi] > pivot){
                hi--;
            }else{
                nums[lo++] = nums[hi];
                break;
            }
        }
        while(lo < hi){
            if(nums[lo] < pivot){
                lo++;
            }else{
                nums[hi--] = nums[lo];
                break;
            }
        }
    }
    nums[lo] = pivot;
    return lo;
}
int findk(vector<int>& nums, int lo, int hi, int k){
    // [lo,hi)
    int mid = partition(nums,lo,hi-1);
    if(mid == nums.size() - k){
        return nums[mid];
    }else if(mid > nums.size() - k){
        return findk(nums,lo,mid,k);
    }else{
        return findk(nums,mid+1,hi,k);
    }

}
int findKthLargest(vector<int>& nums, int k) {
    return findk(nums,0,nums.size(),k);
}

int main(){
    int myArray[] = {1,2};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",findKthLargest(nums,1));
    return 0;
}