#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& res){
    if(x >= obstacleGrid.size() || y >= obstacleGrid[0].size()){
        return 0;
    }else if(res[x][y] != -1){
        return res[x][y];
    }else if(obstacleGrid[x][y] == 1){
        res[x][y] = 0;
        return 0;
    }else{
        int ans = dfs(obstacleGrid,x+1,y,res) + dfs(obstacleGrid,x,y+1,res);
        res[x][y] = ans;
        return ans;
    }
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid.size() == 0) return 0;
    if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1){
        return 0;
    }
    vector<vector<int>> res(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
    res[obstacleGrid.size()-1][obstacleGrid[0].size()-1] = 1;
    return dfs(obstacleGrid,0,0,res);
}
int main(){
    return 0;
}