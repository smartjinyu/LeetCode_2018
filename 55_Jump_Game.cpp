#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums) {
    if(nums.size() <= 1) return true;
    int lastPos = nums.size() - 1;
    for(int i = nums.size() - 2; i >= 0; i--){
        if(nums[i] + i >= lastPos) lastPos = i;
    }
    return lastPos == 0;
}

int main(){
    int myArray[] = {2,2,1,0,4};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",canJump(nums));
    return 0;
}