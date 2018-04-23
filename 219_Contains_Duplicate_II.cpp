#include <vector>
#include <unordered_map>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.size() < 2 || k <= 0) return false;
    if(k >= nums.size()) k = nums.size() - 1;
    unordered_map<int,int> um;
    for(int i = 0; i <= k; i++){
        um[nums[i]]++;
        if(um[nums[i]] > 1) return true;
    }
    int lo = 0, hi = k;
    while(hi < nums.size() - 1){
        um[nums[lo]]--;
        lo++;
        hi++;
        um[nums[hi]]++;
        if(um[nums[hi]] > 1) return true;
    }
    return false;
}

int main(){
    return 0;
}