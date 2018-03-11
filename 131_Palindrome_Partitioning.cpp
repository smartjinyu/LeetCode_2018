#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
bool isPalindrome(string s){
    if(s.size() <= 1){
        return true;
    }
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l++] != s[r--]){
            return false;
        }
    }
    return true;
}

void partitionRec(string s, int n,vector<string>& curRes, vector<vector<string>>& ans){
    if(n == s.size()){
        ans.push_back(curRes);
        return;
    }
    for(int i = 1; i <= s.size() - n; i++){
        if(isPalindrome(s.substr(n,i))){
            curRes.push_back(s.substr(n,i));
            partitionRec(s,n+i,curRes,ans);
            curRes.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans; vector<string> curRes;
    if(s.size() == 0){
        return ans;
    }
    partitionRec(s,0,curRes,ans);
    return ans;
}

int main(){
    vector<vector<string>> ans = partition("aab");
    for(vector<string> vec : ans){
        for(string str : vec){
            printf("%s ",str);
        }
        printf("\n");
    }
    return 0;
}
