#include <vector>
#include <iostream>
using namespace std;
int ans = 0;
int getLongest(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp){
    if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()){
        return 0;
    }else if(dp[x][y] != 0){
        return dp[x][y];
    }else{
        int res = 0;
        if(x > 0 && matrix[x][y] > matrix[x-1][y]){
            res = max(res,getLongest(matrix,x-1,y,dp));
        }
        if(x < matrix.size() - 1 && matrix[x][y] > matrix[x+1][y]){
            res = max(res,getLongest(matrix,x+1,y,dp));
        }
        if(y > 0 && matrix[x][y] > matrix[x][y-1]){
            res = max(res,getLongest(matrix,x,y-1,dp));
        }
        if(y < matrix[0].size() - 1 && matrix[x][y] > matrix[x][y+1]){
            res = max(res,getLongest(matrix,x,y+1,dp));
        }
        res++;
        dp[x][y] = res;
        ans = max(ans,res);
        return res;
    }
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.size() == 0) return 0;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            getLongest(matrix,i,j,dp);
        }
    }
    return ans;
}

int main(){
    return 0;
}