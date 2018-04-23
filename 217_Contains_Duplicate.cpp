#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    if(nums.size() < 2) return false;
    unordered_map<int,int> um;
    for(int num : nums) um[num]++;
    for(auto it = um.begin(); it != um.end(); ++it){
        if(it->second > 1) return true;
    }
    return false;
}
int main(){
    return 0;
}