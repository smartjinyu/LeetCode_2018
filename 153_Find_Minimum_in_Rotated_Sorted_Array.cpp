#include <iostream>
#include <vector>
// Why such a easy problem is classified as medium?
int findMin(vector<int>& nums) {
    if(nums.size() == 0) return -1;
    int first = nums[0];
    for(int num : nums){
        if(num < first){
            return num;
        }
    }
    return first;
}
int main(){
    return 0;
}