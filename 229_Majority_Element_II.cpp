#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    if(nums.size() == 0) return res;
    int cnt1 = 0, cnt2 = 0, candi1 = 0, candi2 = 1;
    for(int num : nums){
        if(num == candi1){
            cnt1++;
        }else if(num == candi2){
            cnt2++;
        }else if(cnt1 == 0){
            cnt1++;
            candi1 = num;
        }else if(cnt2 == 0){
            cnt2++;
            candi2 = num;
        }else{
            cnt1--; cnt2--;
        }
    }
    cnt1 = 0; cnt2 = 0;
    for(int num : nums){
        if(num == candi1) cnt1++;
        if(num == candi2) cnt2++;
    }
    if(cnt1 > nums.size()/3) res.push_back(candi1);
    if(cnt2 > nums.size()/3) res.push_back(candi2);
    return res;
}
int main(){
    return 0;
}