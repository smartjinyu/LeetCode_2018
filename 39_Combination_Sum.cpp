#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void combine(vector<int>& candidates, int target, int begin, vector<int>& cur, vector<vector<int>>& res){
    if(target == 0){
        res.push_back(cur);
    }else if(begin == candidates.size() || target < candidates[begin]){
        return;
    }else{
        for(int i = begin; i < candidates.size() && candidates[i] <= target; i++){
            int num = candidates[i];
            cur.push_back(num);
            combine(candidates, target - num, i, cur, res);
            cur.pop_back();
        }
    }
    
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> res;
    vector<int> cur;
    combine(candidates, target, 0, cur, res);
    return res;
    
}
int main(){
    return 0;
}