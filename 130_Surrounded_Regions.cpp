#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void replace(vector<vector<char>>& board, int x,int y,char o, char c){
    // o is the origin char, c is the new char
    int m = board.size() - 1;
    int n = board[0].size() - 1;
    board[x][y] = c;
    if(x > 0 && (board[x-1][y] == o)) replace(board,x-1,y,o,c);
    if(x < m && (board[x+1][y] == o)) replace(board,x+1,y,o,c);
    if(y > 0 && (board[x][y-1] == o)) replace(board,x,y-1,o,c);
    if(y < n && (board[x][y+1] == o)) replace(board,x,y+1,o,c);

}

void solve(vector<vector<char>>& board) {
    if(board.size() <= 1){
        return;
    }
    int m = board.size() - 1, n = board[0].size() - 1;
    vector<pair<int,int>> maps;
    for(int i = 0; i <= m; i++){
        if(board[i][0] == 'O') { replace(board,i,0,'O','J'); maps.push_back({i,0});}
        if(board[i][n] == 'O') { replace(board,i,n,'O','J'); maps.push_back({i,n});}
    }
    for(int j = 0; j <= n; j++){
        if(board[0][j] == 'O') { replace(board,0,j,'O','J'); maps.push_back({0,j});}
        if(board[m][j] == 'O') { replace(board,m,j,'O','J'); maps.push_back({m,j});}
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
        }
    }
    for(pair<int,int> p : maps){
        replace(board,p.first,p.second,'J','O');
    }

}

int main(){
    return 0;
}
