#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the content in <Sword Towards Offer>
int getFirstOne(int n){
    // return the index of first one from right in its binary representation
    int index = 0;
    while(index < 8 * sizeof(int) && (1&(n >> index)) == 0){
        index++;
    }
    return index;
}
vector<int> singleNumber(vector<int>& nums) {
    if(nums.size() < 3) return nums;
    int xorResult = 0;
    for(int num : nums){
        xorResult ^= num;
    }
    int index = getFirstOne(xorResult);
    vector<int> ans(2,0);
    for(int num : nums){
        if((1 & (num >> index)) == 1){
            ans[0] ^= num;
        }else{
            ans[1] ^= num;
        }
    }
    return ans;
}
int main(){
    return 0;
}