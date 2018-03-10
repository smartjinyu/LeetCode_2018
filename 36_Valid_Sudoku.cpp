#include <iostream>
#include <vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9] = {0};
    int column[9][9] = {0};
    int subbox[9][9] = {0};
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[i][j] !='.'){
                int num = (int)board[i][j] - 49;
                int x = i/3*3 + j/3;
                if(row[i][num] || column[j][num] || subbox[x][num]){
                    return false;
                }else{
                    row[i][num] = 1;
                    column[j][num] = 1;
                    subbox[x][num] = 1;
                }
            }
        }
    }
    return true;
}

int main(){
    return 0;
}