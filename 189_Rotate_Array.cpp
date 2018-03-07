#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    int temp = 0;
    int times = 0; // number of elements exchanged
    for(int i = 0; i < k && times < nums.size(); i++){
        temp = nums[i];
        int j = i;
        bool flag = true; // whether it is the first time j == i
        while(j != i || flag){
            flag = false;
            j += k;
            j %= nums.size();
            swap(temp,nums[j]);
            times++;
        }
    }
    for(int num : nums){
        printf("%d ",num);
    }

}

int main(){
    int myArray[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    rotate(nums,8);
    return 0;
}