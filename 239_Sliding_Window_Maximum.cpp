#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    if(nums.size() < k || k <= 0) return ans;
    deque<int> de;
    for(int i = 0; i < nums.size(); i++){
        if(!de.empty() && de.front() <= i - k) de.pop_front();
        while(!de.empty() && nums[de.back()] < nums[i]) de.pop_back();
        de.push_back(i);
        if(i >= k-1) ans.push_back(nums[de.front()]);
    }
    return ans;
}
int main(){
    return 0;
}