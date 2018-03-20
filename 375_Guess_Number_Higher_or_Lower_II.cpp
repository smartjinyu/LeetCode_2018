#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
int getAmount(int lo, int hi,vector<vector<int>>& ans){
    if(hi <= lo){
        return 0;
    }else if(ans[lo][hi] != 0){
        return ans[lo][hi];
    }else{
        int res = INT_MAX;
        for(int i = lo; i <= hi; i++){
            int temp = i + max(getAmount(lo,i-1,ans),getAmount(i+1,hi,ans));
            res = min(res,temp);
        }
        ans[lo][hi] = res;
        return res;
    }
    
}
int getMoneyAmount(int n) {
    vector<vector<int>> ans(n+1,vector<int>(n+1,0));
    return getAmount(1,n,ans);
}
int main(){
    return 0;
}