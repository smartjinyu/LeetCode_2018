#include <iostream>
#include <vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++){
        if(nums[j] != val){
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main(){
    int myArray[] = {4,4,4,4};
    vector<int> nums (myArray,myArray + sizeof(myArray)/sizeof(int));
    int len;
    printf("%d\n",len = removeElement(nums,4));
    for (int i = 0; i < len; i++){
        printf("%d",nums[i]);
    }
    return 0;
}