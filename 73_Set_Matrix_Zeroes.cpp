#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0){
        return;
    }
    int m = matrix.size(), n = matrix[0].size();
    bool col0 = false;
    for(int i = 0; i < m; i++){
        if(matrix[i][0] == 0) col0 = true;
        for(int j = 1; j < n; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++){
        if(matrix[i][0] == 0){
            for(int j = 1; j < n; j++) matrix[i][j] = 0;
        }
    }
    for(int j = 1; j < n; j++){
        if(matrix[0][j] == 0){
            for(int i = 1; i < m; i++) matrix[i][j] = 0;
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 1; j < n; j++) matrix[0][j] = 0;
    }
    if(col0){
        for(int i = 0; i < m; i++) matrix[i][0] = 0;
    }
}

int main(){
    return 0;
}