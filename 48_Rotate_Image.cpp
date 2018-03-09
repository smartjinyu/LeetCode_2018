#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    if(matrix.size() == 1){
        return;
    }
    reverse(matrix.begin(),matrix.end());
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

}

int main(){
    int myArray1[] = {1,2,3,4};
    int myArray2[] = {5,6,7,8};
    int myArray3[] = {9,10,11,12};
    int myArray4[] = {13,14,15,16};
    
    vector<int> line1(myArray1,myArray1 + sizeof(myArray1)/sizeof(int));
    vector<int> line2(myArray2,myArray2 + sizeof(myArray2)/sizeof(int));
    vector<int> line3(myArray3,myArray3 + sizeof(myArray3)/sizeof(int));
    vector<int> line4(myArray4,myArray4 + sizeof(myArray4)/sizeof(int));

    vector<vector<int>> matrix;
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    matrix.push_back(line4);
    rotate(matrix);
    for(vector<int> line : matrix){
        for(int num : line){
            printf("%d ",num);
        }
        printf("\n");
    }

    return 0;
}