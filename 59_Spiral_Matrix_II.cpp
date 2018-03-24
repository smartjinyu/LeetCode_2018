#include <iostream>
#include <vector>
using namespace std;
void fill(vector<vector<int>>& ans, int x, int y, int dir, int len, int begin){
    // dir is direction, 0 from left to right, 1 from right to left, 2 from top to bottom, 3 from bottom to top
    if(len == 0) return;
    if(dir == 0){
        // from left to right
        for(int i = 0; i < len; i++){
            ans[x][y + i] = begin + i;
        }
        fill(ans,x+1,y+len-1,2,len-1,begin+len);
    }else if(dir == 2){
        // from top to bottom
        for(int i = 0; i < len; i++){
            ans[x+i][y] = begin + i;
        }
        fill(ans,x+len-1,y-1,1,len,begin+len);
    }else if(dir == 1){
        // from right to left
        for(int i = 0; i < len; i++){
            ans[x][y-i] = begin + i;
        }
        fill(ans,x-1,y-len+1,3,len-1,begin+len);
    }else{
        // from bottom to top
        for(int i = 0; i < len; i++){
            ans[x-i][y] = begin + i;
        }
        fill(ans,x-len+1,y+1,0,len,begin+len);
    }
}
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n,vector<int>(n,0));
    if(n == 0) return ans;
    if(n == 1){
        ans[0][0] = 1;
        return ans;
    }
    fill(ans,0,0,0,n,1);
    return ans;
}
int main(){
    return 0;
}