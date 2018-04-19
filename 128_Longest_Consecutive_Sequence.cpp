#include <iostream>
#include <vector>
using namespace std;
int longestConsecutive(vector<int>& nums) {
    if(nums.size() < 2) return nums.size();
    unordered_map<int,int> um;
    int mini = INT_MAX; int maxi = INT_MIN;
    for(int num : nums) um[num]++;
    int maxLen = 1;
    int len = 1;
    int curNum;
    for(int num : nums){
        if(um[num-1] != 0) continue; // only consider the starting num
        curNum = num + 1;
        len = 1;
        while(um[curNum] > 0){
            len++;
            curNum++;
        }
        maxLen = max(maxLen, len);
    }
    return maxLen;
}

int main(){
    return 0;
}