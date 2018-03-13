#include <iostream>
#include <vector>
using namespace std;
void printMatrix(vector<vector<int>>& matrix,vector<int>& ans, int decay, int x, int y,int orient){
    // orient 0: from left to right, 1 right to left, 2 top to bottom, 3 bottom to up
    int m = matrix.size(), n = matrix[0].size();
    switch(orient){
        case 0: if(n == decay) return;
                for(int j = y; j < y + n - decay; j++) ans.push_back(matrix[x][j]);
                printMatrix(matrix,ans,decay+1,x+1,y+n-decay-1,2); 
                break;
        case 1: if(n == decay) return;
                for(int j = y; j > y - n + decay; j--) ans.push_back(matrix[x][j]);
                printMatrix(matrix,ans,decay+1,x-1,y-n+decay+1,3);
                break;
        case 2: if(m == decay) return;
                for(int i = x; i < x + m - decay; i++) ans.push_back(matrix[i][y]);
                printMatrix(matrix,ans,decay,x+m-decay-1,y-1,1);
                break;
        case 3: if(m == decay) return;
                for(int i = x; i > x - m + decay; i--) ans.push_back(matrix[i][y]);
                printMatrix(matrix,ans,decay,x-m+decay+1,y+1,0);
                break;
    }

}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if(matrix.size() == 0) return ans;
    printMatrix(matrix,ans,0,0,0,0);
    return ans;
}

int main(){
    int myArray1[] = {1}; vector<int> line1(myArray1, myArray1 + sizeof(myArray1)/sizeof(int));
    int myArray2[] = {6}; vector<int> line2(myArray2, myArray2 + sizeof(myArray2)/sizeof(int));
    int myArray3[] = {11,12,13,14,15}; vector<int> line3(myArray3, myArray3 + sizeof(myArray3)/sizeof(int));
    int myArray4[] = {16,17,18,19,20}; vector<int> line4(myArray4, myArray4 + sizeof(myArray4)/sizeof(int));
    vector<vector<int>> matrix; matrix.push_back(line1); matrix.push_back(line2);// matrix.push_back(line3); matrix.push_back(line4);
    vector<int> ans = spiralOrder(matrix);
    for(int num : ans) printf("%d ",num);
    return 0;
}