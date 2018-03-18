#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    vector<vector<int>> map(matrix.size(),vector<int>(matrix[0].size(),0));
    int ans = 0;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == '1'){
                if(i == 0 || j == 0){
                    map[i][j] = 1; ans = max(ans,1);
                }else{
                    int res = min(map[i-1][j],min(map[i-1][j-1],map[i][j-1])) + 1;
                    ans = max(ans,res);
                    map[i][j] = res;
                }
            }
        }
    }
    return ans*ans;
}
int main(){
    return 0;
}