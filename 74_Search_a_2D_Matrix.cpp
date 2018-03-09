#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(m == 0) return false;
    int n = matrix[0].size();
    if(n == 0) return false;
    int l = 0, r = m*n, mid = 0;
    while(l < r){
        mid = (l + r)/2;
        if(target < matrix[mid/n][mid%n]){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    if(l>0)l--;
    if(matrix[l/n][l%n] == target){
        return true;
    }else{
        return false;
    }
}

int main(){
    int myArray1[] = {1}; vector<int> line1(myArray1, myArray1 + sizeof(myArray1)/sizeof(int));
    int myArray2[] = {10, 11, 13}; vector<int> line2(myArray2, myArray2 + sizeof(myArray2)/sizeof(int));
    int myArray3[] = {16, 18, 20}; vector<int> line3(myArray3, myArray3 + sizeof(myArray3)/sizeof(int));
    vector<vector<int>> matrix;
    matrix.push_back(line1); //matrix.push_back(line2); matrix.push_back(line3);
    printf("%d\n",searchMatrix(matrix,1));
    return 0;
}