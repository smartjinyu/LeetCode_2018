#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> um;
    for(int num : nums){
        um[num]++;
    }
    for(int num : nums){
        if(um[num] > nums.size()/2){
            return num;
        }
    }
}

int main(){
    int myArray[] = {1,1,2,2,3,3,3,3,3,3};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",majorityElement(nums));
    return 0;
}