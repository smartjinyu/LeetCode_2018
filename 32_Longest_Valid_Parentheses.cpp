#include <iostream>
#include <vector>
using namespace std;
// This solution is based on the solution in LeetCode
int longestValidParentheses(string s) {
    if(s.size() < 1) return 0;
    vector<int> dp(s.size(),0); // dp[i] = longest valid parentheses ended in s[i] 
    int ans = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ')'){
            if(s[i-1] == '('){
                if(i >= 2) dp[i] = dp[i-2] + 2;
                else dp[i] = 2;
            }else{
                // s[i-1] == ')'
                if(i - dp[i-1] >= 1 && s[i-dp[i-1]-1] == '('){
                    if(i-dp[i-1]-2 >= 0){
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                    }else{
                        dp[i] = dp[i-1] + 2;
                    }
                } // else dp[i] = 0
            }
            ans = max(ans,dp[i]);
        }
    }
    return ans;
}

int main(){
    return 0;
}