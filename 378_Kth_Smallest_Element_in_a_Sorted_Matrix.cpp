#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];
    int mid = 0, cnt = 0, j = n-1;
    while(left < right){
        mid = (left + right)/2;
        cnt = 0; j = n - 1;
        for(int i = 0; i < n; i++){
            while(j >= 0 && matrix[i][j] > mid) j--;
            cnt += (j+1);
        }
        if(cnt < k){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;
}

int main(){
    int myArray1[] = {1, 5, 9}; vector<int> line1(myArray1, myArray1 + sizeof(myArray1)/sizeof(int));
    int myArray2[] = {10, 11, 13}; vector<int> line2(myArray2, myArray2 + sizeof(myArray2)/sizeof(int));
    int myArray3[] = {12, 13, 15}; vector<int> line3(myArray3, myArray3 + sizeof(myArray3)/sizeof(int));
    vector<vector<int>> matrix;
    matrix.push_back(line1); matrix.push_back(line2); matrix.push_back(line3);
    printf("%d\n",kthSmallest(matrix,8));
    return 0;
}