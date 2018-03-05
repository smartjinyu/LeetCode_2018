#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    // binary search
    int a = 0, b = nums.size() - 1;
    int p = 0;
    while(b-a > 1){
        p = (a+b)/2;
        if (nums[p] > target){
            b = p;
        }else{
            a = p;
        }
    }
    printf("a = %d, b = %d\n",a,b);
    if(target <= nums[a]){
        return a;
    } else if (nums[b] < target){
        return b + 1;
    } else{
        return b;
    }
}

int main(){
    int myArray[] = {1,3,5,6,7,8,11,13};
    vector<int> nums (myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",searchInsert(nums,2));
    return 0;
}