#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the content in <Sword Towards Offer>
int singleNumber(vector<int>& nums) {
    if(nums.size() == 0) return -1;
    if(nums.size() == 1) return nums[0];
    vector<int> bitSum(32,0);
    int bitMask = 1;
    for(int num : nums){
        bitMask = 1;
        for(int i = 31; i >= 0; i--){
            if((num & bitMask) != 0){
                bitSum[i]++;
            }
            bitMask = bitMask << 1;
        }       
    }
    int ans = 0;
    for(int i = 0; i < 32; i++){
        ans = ans << 1;
        if(bitSum[i] % 3 != 0){
            ans += 1;
        }            

    }
    return ans;
}
int main(){
    return 0;
}