#include <iostream>
#include <unordered_map>
using namespace std;
bool isValid(string& s1,string& s2, unordered_map<char,int> um, int lo, int hi){
    if(hi - lo < s1.size()) return false;
    int l = lo, h = lo;
    int cnt = s1.size();
    while(h < hi){
        if(um[s2[h]] > 0){
            cnt--;
        }
        um[s2[h]]--;
        h++;
        while(cnt == 0){
            if(h - l == s1.size()) return true;
            if(um[s2[l]] >= 0){
                cnt++;
            }
            um[s2[l]]++; l++; 
        }
    }
    return false;
}
bool checkInclusion(string s1, string s2) {
    unordered_map<char,int> um;
    for(char c : s1) um[c]++;
    int lo = 0, hi = 0;
    bool ans = false;
    while(hi < s2.size()){
        while(lo < s2.size() && um[s2[lo]] == 0) lo++;
        hi = lo + 1;
        while(lo < s2.size() && um[s2[hi]] != 0) hi++;
        // [lo,hi) is a possible interval
        ans = isValid(s1,s2,um,lo,hi);
        if(ans) return true;
        lo = hi;
    }
    return false;
}
int main(){
    return 0;
}