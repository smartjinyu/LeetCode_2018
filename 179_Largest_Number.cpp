#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool comp(int a, int b){
    string s1 = to_string(a) + to_string(b);
    string s2 = to_string(b) + to_string(a);
    int res = s1.compare(s2);
    return res > 0;
}
string largestNumber(vector<int>& nums) {
    if(nums.size() == 0) return "";
    sort(nums.begin(),nums.end(),comp);
    string ans; bool flag = true;
    if(nums[0] == 0) return "0";
    for(int num : nums){
        ans += to_string(num);
        flag = false;
    }
    return ans;
    
}
int main(){
    return 0;
}