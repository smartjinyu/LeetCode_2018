#include <iostream>
#include <unordered_map>
using namespace std;
// This solution is based on the discuss in LeetCode
string minWindow(string s, string t) {
    if(s.size() == 0) return "";
    if(t.size() == 0) return s;
    unordered_map<char,int> um;
    for(char c : t) um[c]++;
    int cnt = t.size(); int lo = 0, end = 0;
    int start = 0, minLen = INT_MAX;
    while(end < s.size()){
        if(um[s[end]] > 0){
            cnt--;
        }
        um[s[end]]--; end++;
        while(cnt == 0){
            if(end - lo < minLen){
                start = lo; minLen = end - lo ;
            }
            if(um[s[lo]] >= 0){
                cnt++;
            }
            um[s[lo]]++;
            lo++;
        }
    }
    if(minLen == INT_MAX){
        return "";
    }else{
        return s.substr(start,minLen);
    }
}
int main(){
    return 0;
}