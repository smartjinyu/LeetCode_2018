#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void sortColors(vector<int>& nums) {
    int zero = 0, second = nums.size() - 1;
    for(int i = 0; i <= second; i++){
        while(nums[i] == 0 && zero < i) swap(nums[i],nums[zero++]);
        while(nums[i] == 2 && i < second) swap(nums[i],nums[second--]);
        while(nums[i] == 0 && zero < i) swap(nums[i],nums[zero++]);
    }
    printf("first = %d, second = %d\n",zero,second);
}

int main(){
    int myArray[] = {1,0};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    sortColors(nums);
    for(int num : nums){
        printf("%d",num);
    }
    return 0;
}