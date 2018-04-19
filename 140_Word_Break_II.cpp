#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
void dfs(string& s, vector<string>& wordDict, int begin, int maxLen, vector<string>& cur, vector<string>& ans){
    // edge case
    if(begin == s.size()){
        if(cur.size() != 0){
            string str = cur[0];
            for(int i = 1; i < cur.size(); i++){
                str += " ";
                str += cur[i];
            }
            ans.push_back(str);
        }
        return;
        
    }
    for(int i = begin; i < s.size() && i < begin + maxLen; i++){
        auto it = find(wordDict.begin(),wordDict.end(),s.substr(begin,i-begin+1));
        if(it != wordDict.end()){
            cur.push_back(*it);
            dfs(s, wordDict, i+1, maxLen, cur, ans);
            cur.pop_back();
        }
    }
}
bool canWordBreak(string s, vector<string>& wordDict) {
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

vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<string> ans;
    if(wordDict.size() == 0) return ans;
    if(!canWordBreak(s,wordDict)) return ans;
    int maxLen = 0;
    for(const string& str : wordDict) maxLen = max(maxLen,(int) str.size());
    vector<string> cur;
    dfs(s, wordDict, 0, maxLen, cur, ans);
    return ans;
}
int main(){
    return 0;
}