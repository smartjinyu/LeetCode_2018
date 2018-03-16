#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int lo = 0, hi = numbers.size() - 1;
    while(lo <= hi && numbers[lo] + numbers[hi] != target){
        if(numbers[lo] + numbers[hi] < target){
            lo++;
        }else{
            hi--;
        }
    }
    ans.push_back(lo+1); ans.push_back(hi+1);
    return ans;
}

int main(){
    int myArray[] = {1,3,5,6,7,11,20};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    vector<int> ans = twoSum(nums,16);
    printf("[%d,%d]\n",ans[0],ans[1]);
    return 0;
}