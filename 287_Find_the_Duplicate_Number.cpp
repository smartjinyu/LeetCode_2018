#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int findDuplicate(vector<int>& nums) {
    int fast = nums[nums[0]];
    int slow = nums[0];
    while(true){
        if(fast == slow){
            break;
        }else{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
    }
    fast = 0;
    while(fast != slow){
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}

int main(){
    int myArray[] = {1,3,4,2,1};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",findDuplicate(nums));
    return 0;
}
