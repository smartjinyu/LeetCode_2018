#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// This solution is in reference to the discuss in LeetCode
bool increasingTriplet(vector<int>& nums) {
    int s1 = INT_MAX, s2 = INT_MAX; // s1 < s2
    for(int num : nums){
        if(num < s2){
            if(num < s1){
                s1 = num;
            }else if(num > s1){
                s2 = num;
            }
        }else if(num > s2){
            return true;
        }
    }
    return false;
}

int main(){
    int myArray[] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",increasingTriplet(nums));
}