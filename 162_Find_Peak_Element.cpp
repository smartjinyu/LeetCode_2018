#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int findPeak(vector<int>& nums,int l, int r){
    if(l == r){
        return l;
    }
    int mid = (l + r)/2;
    if(nums[mid] < nums[mid + 1]){
        return findPeak(nums,mid+1,r);
    }else{
        return findPeak(nums,l,mid);
    }
}
int findPeakElement(vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    return findPeak(nums,0,nums.size()-1);
}

int main(){
    int myArray[] = {1,3,5,2,3,1};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",findPeakElement(nums));
    return 0;
}