#include <iostream>
#include <vector>
using namespace std;
int combine(vector<int>& nums, int target, vector<int>& res){
    if(target < 0){
        return 0;
    }else if(res[target] != -1){
        return res[target];
    }else{
        int ans = 0;
        for(auto num : nums){
            ans += combine(nums,target - num, res);
        }
        res[target] = ans;
        return ans;
    }

}
int combinationSum4(vector<int>& nums, int target) {
    if(nums.size() == 0) return 0;
    vector<int> res(target + 1,-1); 
    // res[n] = combinations sum to n
    res[0] = 1;
    return combine(nums, target, res);

}

int main(){
    int myArray[] = {1,2,3};
    vector<int> nums(myArray, myArray + sizeof(myArray)/sizeof(int));
    printf("%d\n",combinationSum4(nums,4));
    return 0;
}