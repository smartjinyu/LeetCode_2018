#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int cnt = 0;
    for(int num : nums){
        if(num == 0){
            cnt++;
        }
    }
    if(cnt == 0) return;
    int j = 0;
    for(int num : nums){
        if(num != 0){
            nums[j++] = num;
        }
    }
    for(int i = nums.size() - cnt; i < nums.size(); i++){
        nums[i] = 0;
    }
}

int main(){
    int myArray[] = {0,1};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    moveZeroes(nums);
    for(int num : nums){
        printf("%d ",num);
    }
    return 0;
}