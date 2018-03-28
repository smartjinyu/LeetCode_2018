#include <iostream>
#include <vector>
using namespace std;
string reverse(string& s){
    string str(s.size(),' ');
    for(int i = 0; i < s.size(); i++){
        str[i] = s[s.size() - 1 - i];
    }
    return str;
}
int longestPalindromeSubseq(string s) {
    if(s.size() < 2) return s.size();
    string s1 = reverse(s);
    vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= s1.size(); j++){
            if(s[i-1] == s1[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s.size()][s1.size()];
}
int main(){
    return 0;
}