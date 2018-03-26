#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& triangle, int level, int id, vector<vector<int>>& dp){
    if(dp[level][id] != INT_MAX){
        return dp[level][id];
    }else{
        int ans = min(dfs(triangle,level+1,id,dp),dfs(triangle,level+1,id+1,dp)) + triangle[level][id];
        dp[level][id] = ans;
        return ans;
    }
}
int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.size() == 0) return 0;
    if(triangle.size() == 1) return triangle[0][0];
    vector<vector<int>> dp(triangle.size()-1, vector<int>(triangle[triangle.size()-1].size(),INT_MAX));
    dp.push_back(triangle[triangle.size()-1]);
    // dp[i][j] min sum from triangle[i][j] to bottom
    dfs(triangle,0,0,dp);
    return dp[0][0];
}
int main(){
    return 0;
}