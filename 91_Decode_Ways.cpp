#include <iostream>
#include <vector>
using namespace std;
int getNum(string s, int begin, vector<int>& dp){
    if(begin >=  s.size()){
        return 0;
    }else if(dp[begin] != -1){
        return dp[begin];
    }else{
        if(s[begin] == '0'){
            dp[begin] = 0;
            return 0;
        }else{
            int ans = getNum(s,begin+1,dp);
            if(s[begin] == '1' || (s[begin] == '2' && s[begin+1] <= '6')){
                ans += getNum(s,begin+2,dp);
            }
            dp[begin] = ans;
            return ans;
        }
    }
}
int numDecodings(string s) {
    if(s.size() == 0) return 0;
    else if(s.size() == 1){
        if(s[0] == '0'){
            return 0;
        }else{
            return 1;
        }
    }
    vector<int> dp(s.size(),-1);
    if(s[s.size() - 1] == '0'){
        dp[s.size() - 1] = 0;
    }else{
        dp[s.size() - 1] = 1;     
    }
    dp[s.size() - 2] = dp[s.size() - 1];
    if(s[s.size() - 2] == '0'){
        dp[s.size() - 2] = 0;
    }else if(s[s.size() - 2] == '1' || (s[s.size() - 2] == '2' && s[s.size() - 1] <= '6')){
        dp[s.size() - 2]++;
    }
    int ans = getNum(s,0,dp);
    return ans;
    
}
 int main(){
     return 0;
 }
