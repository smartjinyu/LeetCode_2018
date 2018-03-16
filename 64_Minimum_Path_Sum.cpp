#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
vector<vector<int>> cost;
int minSum(vector<vector<int>>& grid,int x, int y){
    // minSum from (x,y) to (m-1,n-1)
    if(cost[x][y] != INT_MAX){
        return cost[x][y];
    }else{
        int res = grid[x][y];
        if(x == grid.size() - 1){
            res += minSum(grid,x,y+1);
        }else if(y == grid[0].size() - 1){
            res += minSum(grid,x+1,y);
        }else{
            res += min(minSum(grid,x+1,y),minSum(grid,x,y+1));
        }
        cost[x][y] = res;
        return res;
    }


}
int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<int> c(n,INT_MAX); cost.resize(m,c);
    cost[m-1][n-1] = grid[m-1][n-1];
    return minSum(grid,0,0);
}

int main(){
    int myArray1[] = {1,2,3,4}; vector<int> line1(myArray1,myArray1 + sizeof(myArray1)/sizeof(int));
    int myArray2[] = {4,1,2,1}; vector<int> line2(myArray2,myArray2 + sizeof(myArray2)/sizeof(int));
    int myArray3[] = {5,6,2,6}; vector<int> line3(myArray3,myArray3 + sizeof(myArray3)/sizeof(int));
    int myArray4[] = {1,3,1,2}; vector<int> line4(myArray4,myArray4 + sizeof(myArray4)/sizeof(int));
    vector<vector<int>> grid;
    grid.push_back(line1); grid.push_back(line2); grid.push_back(line3); grid.push_back(line4);
    printf("%d\n",minPathSum(grid));

    return 0;
}