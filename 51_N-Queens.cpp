#include <iostream>
#include <vector>
using namespace std;
void backtracking(int cur, int n,vector<vector<int>>& vis,vector<int>& map,vector<vector<string>>& ans){
    if(cur == n){
        // success 
        string str(n,'.');
        vector<string> res(n,str);
        for(int i = 0; i < n; i++){
            res[i][map[i]] = 'Q';
        }
        ans.push_back(res);
        return;
    }else{
        // cur puts in cur-th row
        for(int i = 0; i < n; i++){
            // each column
            if(vis[0][i] == 0 && vis[1][cur+i] == 0 && vis[2][cur-i+n] == 0){
                // column - sub diagonal - main diagonal
                map[cur] = i;
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                backtracking(cur+1,n,vis,map,ans);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if(n == 0) return ans;
    vector<vector<int>> vis(3,vector<int>(2*n+1,0));
    vector<int> map(n,0);
    backtracking(0,n,vis,map,ans);
    return ans;
}

int main(){
    return 0;
}