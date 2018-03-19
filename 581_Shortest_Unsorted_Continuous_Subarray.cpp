#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int findUnsortedSubarray(vector<int>& nums) {
    if(nums.size() <= 1) return 0;
    stack<int> sk;
    sk.push(0);
    int i = 1;
    int left = nums.size();
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] >= nums[i-1]){
            sk.push(i);
        }else{
            int pivot = nums[i]; // the first element nums[i] < nums[i-1]
            while(!sk.empty() && nums[sk.top()] > pivot){
                sk.pop();
            }
            if(!sk.empty()) left = min(left,sk.top() + 1);
            else left = 0;
        }
    }
    if(left == nums.size()) return 0;
    
    stack<int> sk2;
    sk2.push(nums.size() - 1);
    int right = 0;
    for(int j = nums.size() - 2; j >= 0; j--){
        if(nums[j] <= nums[j+1]){
            sk2.push(j);
        }else{
            int pivot = nums[j];
            while(!sk2.empty() && nums[sk2.top()] < pivot){
                sk2.pop();
            }
            if(!sk2.empty()) right = max(right,sk2.top() - 1);
            else right = nums.size() - 1;
        }
    }
    printf("left = %d, right = %d\n",left,right);
    return right - left + 1;
}

int main(){
    int myArray[] = {2, 1,3,4,5};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",findUnsortedSubarray(nums));
}
