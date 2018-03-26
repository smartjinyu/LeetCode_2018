#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
void backtrack(int cur, int n, vector<vector<int>>& vis){
    if(cur == n){
        ans++; return;
    }else{
        for(int i = 0; i < n; i++){
            // columns
            if(vis[0][i] == 0 && vis[1][cur+i] ==0 && vis[2][cur-i+n] == 0){
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
                backtrack(cur+1,n,vis);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
            }
        }
    }
}
int totalNQueens(int n) {
    if(n <= 1) return n;
    vector<vector<int>> vis(3,vector<int>(2*n + 1,0));
    backtrack(0,n,vis);
    return ans;
}
int main(){
    return 0;
}