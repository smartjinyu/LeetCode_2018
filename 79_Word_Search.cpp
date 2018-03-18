#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the dicuss in LeetCode
bool dfs(vector<vector<char>>& board, string word,int begin, int x, int y){
    if(begin == word.size()){
        return true;
    }else if(x < 0 || x == board.size() || y < 0 || y == board[0].size() || board[x][y] != word[begin]){
        return false;
    }else{
        board[x][y] = '*';
        bool ans = dfs(board,word,begin+1,x-1,y) || dfs(board,word,begin+1,x+1,y) || dfs(board,word,begin+1,x,y+1) || dfs(board,word,begin+1,x,y-1);
        board[x][y] = word[begin];
        return ans;
    }
}
bool exist(vector<vector<char>>& board, string word) {
    if(board.size() == 0) return false;
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(dfs(board,word,0,i,j)){
                return true;
            }
        }
    }
    return false;
    
}

int main(){
    return 0;
}