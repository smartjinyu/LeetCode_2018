#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
int lenOfPalin(string& s,int lo, int hi){
    while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
        lo--;
        hi++;
    }
    return hi - lo - 1;
}
string longestPalindrome(string s) {
    if(s.size() == 0) return "";
    int maxLen = -1, start = -1;
    for(int i = 0; i < s.size(); i++){
        int len1 = lenOfPalin(s,i,i);
        if(len1 > maxLen){
            maxLen = len1;
            start = i - len1/2;
        }
        int len2 = lenOfPalin(s,i,i+1);
        if(len2 > maxLen){
            maxLen = len2;
            start = i - len2/2 + 1;
        }
    }
    return s.substr(start,maxLen);
}
int main(){
    return 0;
}