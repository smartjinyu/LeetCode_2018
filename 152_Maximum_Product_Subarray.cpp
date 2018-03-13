#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int maxProductNoneZero(vector<int>& nums,int lo, int hi){
    // max product of subarray in [lo,hi)
    if(hi <= lo) return 0;
    if(hi - lo == 1) return nums[lo];
    int ans[hi - lo]; int first = -1, last = -1;
    ans[0] = nums[lo];
    if(nums[lo] < 0) first = lo;
    for(int i = lo + 1; i < hi; i++){
        ans[i-lo] = ans[i-1-lo] * nums[i];
        if(nums[i] < 0){
            if(first == -1){
                first = i;
            }else{
                last = i;
            }
        }
    }
    if(ans[hi-1-lo] > 0){
        return ans[hi-1-lo];
    }else if(last == -1){
        int num1 = ans[hi-1-lo]/ans[first-lo];
        int num2 = 0;
        if(first > lo) num2 = ans[first-1-lo];
        return max(num1,num2);
    }else{
        return max(ans[last-1-lo],ans[hi-1-lo]/ans[first-lo]);
    }

}
int maxProduct(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    vector<int> zeroPos;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 0) zeroPos.push_back(i);
    }
    int ans = -INT_MAX;
    if(zeroPos.size() == 0){
        ans = maxProductNoneZero(nums,0,nums.size());
    }else{
        ans = max(ans,maxProductNoneZero(nums,0,zeroPos[0]));
        for(int i = 0; i < zeroPos.size() - 1; i++){
            ans = max(ans,maxProductNoneZero(nums,zeroPos[i]+1,zeroPos[i+1]));
        }
        ans = max(ans,maxProductNoneZero(nums,zeroPos[zeroPos.size()-1]+1,nums.size()));
        ans = max(0,ans);
    }
    return ans;
}

int main(){
    int myArray[] = {1,0,-1,2,3,-5,-2};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",maxProduct(nums));
    return 0;
}