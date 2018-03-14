#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int j = 1, cnt = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == nums[j-1]){
            if(cnt < 2) {nums[j++] = nums[i]; cnt++;}
        }else{
            nums[j++] = nums[i];
            cnt = 1;
        }
    }
    return j;
}

int main(){
    int myArray[] = {1,1,1,1,2,2,2,2,3,4,5};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    int n = removeDuplicates(nums);
    for(int i = 0; i < n; i++){
        printf("%d ",nums[i]);
    }
    return 0;
}