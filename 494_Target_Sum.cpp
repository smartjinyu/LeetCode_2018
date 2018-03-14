#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void permute(vector<int>& nums, int n, int curRes,int S){
    if(n == nums.size()){
        if(curRes == S) ans++;
    }else{
        permute(nums,n+1,curRes+nums[n],S);
        permute(nums,n+1,curRes-nums[n],S);
    }
}
int findTargetSumWays(vector<int>& nums, int S) {
    permute(nums,0,0,S);
    return ans;
}

int main(){
    int myArray[] = {1,1,1,1,1};
    vector<int> nums(myArray,myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",findTargetSumWays(nums,8));
    return 0;
}