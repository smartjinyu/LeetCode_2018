#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void combine(vector<int>& candidates, int target, int begin,vector<int>& cur,vector<vector<int>>& res){
    if(target == 0){
        res.push_back(cur); return;
    }else if(target < 0 || begin == candidates.size() || candidates[begin] > target){
        return;
    }else{
        for(int i = begin; i < candidates.size() && candidates[i] <= target;){
            int num = candidates[i];
            int j = i;
            while(j < candidates.size() && candidates[j] == num) j++; 
            // j is the first candidates[j] != num
            for(int k = 1; k <= j - i; k++){
                cur.push_back(num);
                combine(candidates, target - k*num, j, cur,res);
            }
            for(int k = 1; k <= j - i; k++) cur.pop_back();
            i = j;
        }
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> cur;
    vector<vector<int>> res;
    combine(candidates,target,0,cur,res);
    return res;
}
int main(){
    return 0;
}