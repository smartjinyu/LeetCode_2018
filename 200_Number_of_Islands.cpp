#include <iostream>
#include <vector>
using namespace std;
void submerge(vector<vector<char>>& grid,int x, int y){
    // submerge adjacent islands to sea
    int m = grid.size() - 1, n = grid[0].size() - 1;
    grid[x][y] = '0';
    if(x > 0 && grid[x-1][y] == '1') submerge(grid,x-1,y);
    if(x < m && grid[x+1][y] == '1') submerge(grid,x+1,y);
    if(y > 0 && grid[x][y-1] == '1') submerge(grid,x,y-1);
    if(y < n && grid[x][y+1] == '1') submerge(grid,x,y+1);
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0){
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == '1'){
                cnt++;
                submerge(grid,i,j);
            }
        }
    }
    return cnt;
}

int main(){
    return 0;
}