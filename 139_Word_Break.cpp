#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
bool wordBreak(string s, vector<string>& wordDict) {
    if(wordDict.size() == 0) return false;
    vector<int> dp(s.size()+1,0); // dp[i] == 1 means s[0,i-1] is valid
    dp[0] = 1;
    int maxLen = 0;
    for(string str : wordDict){
        maxLen = max(maxLen, (int)str.size());
    }
    for(int i = 1; i <= s.size(); i++){
        for(int j = i - 1; i - j <= maxLen; j--){
            if(dp[j] == 1 && find(wordDict.begin(),wordDict.end(),s.substr(j,i-j)) != wordDict.end()){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[s.size()];
}
int main(){
    return 0;
}