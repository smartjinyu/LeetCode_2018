#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m == 0) return false;
    int n = matrix[0].size();
    if(n == 0) return false;
    int j = n - 1;
    for(int i = 0; i < m; i++){
        while(j > 0 && matrix[i][j] > target) j--;
        if(matrix[i][j] == target) return true;
    }
    return false;
}


int main(){
    int myArray1[] = {1, 5, 9}; vector<int> line1(myArray1, myArray1 + sizeof(myArray1)/sizeof(int));
    int myArray2[] = {10, 11, 13}; vector<int> line2(myArray2, myArray2 + sizeof(myArray2)/sizeof(int));
    int myArray3[] = {12, 13, 15}; vector<int> line3(myArray3, myArray3 + sizeof(myArray3)/sizeof(int));
    vector<vector<int>> matrix;
    matrix.push_back(line1); matrix.push_back(line2); matrix.push_back(line3);
    printf("%d\n",searchMatrix(matrix,15));
    return 0;
}