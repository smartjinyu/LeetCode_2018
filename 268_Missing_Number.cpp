#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int n = nums.size();
    int res = n*(n+1)/2;
    int ans = 0;
    for(int num : nums) ans += num;
    return res - ans;
}

int main(){
    return 0;
}