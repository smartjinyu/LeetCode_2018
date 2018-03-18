#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    if(nums1.size() == 0 || nums2.size() == 0) return res;
    unordered_map<int,int> um;
    for(int num : nums1) um[num]++;
    for(int num : nums2){
        if(um[num] != 0){
            res.push_back(num);
            um[num] = 0;
        }
    }
    return res;
}
int main(){
    return 0;
}