#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// This solution is based on the discuss in LeetCode
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0) return 0;
    int row = matrix.size(), col = matrix[0].size();
    vector<int> height(col,0);
    int maxArea = 0;
    stack<int> sk;
    int l = 0, h = 0;
    for(int i = 0; i < row; i++){
        // max histogram whose base is matrix[i]
        for(int j = 0; j < col; j++){
            if(matrix[i][j] == '1'){
                height[j]++;
            }else{
                height[j] = 0;
            }
        } // update the height vector
        for(int j = 0; j < col; j++){
            while(!sk.empty() && height[sk.top()] > height[j]){
                h = height[sk.top()]; sk.pop();
                l = sk.empty() ? -1 : sk.top();
                maxArea = max(maxArea,h * (j - l - 1));
            }
            sk.push(j);
        }
        while(!sk.empty()){ // last element
            h = height[sk.top()]; sk.pop();
            l = sk.empty() ? -1 : sk.top();
            maxArea = max(maxArea,h * (col - l - 1));
        }
    }
    return maxArea;
}
int main(){
    return 0;
}