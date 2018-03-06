#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discussion section in LeetCode
int removeDuplicates(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int i = 0;
    for(int j = 1; j < nums.size(); j++){
        if(nums[j] != nums[i]){
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}

int main(){
    int myArray[]={1,1};
    vector<int> nums = vector<int>(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",removeDuplicates(nums));
    return 0;
}