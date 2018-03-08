#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num : nums){
        ans ^= num;
    }
    return ans;
}
int main(){
    int myArray[] = {1,1,2,2,3,3,4,5,5};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",singleNumber(nums));
    return 0;
}
