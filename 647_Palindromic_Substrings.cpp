#include <iostream>
using namespace std;
int ans = 0;
void expand(string& s,int lo, int hi){
    while(lo >= 0 && hi < s.size() && s[lo] == s[hi]){
        lo--;
        hi++;
        ans++;
    }
}
int countSubstrings(string s) {
    for(int i = 0; i < s.size(); i++){
        expand(s,i,i);
        expand(s,i,i+1);
    }
    return ans;
}
int main(){
    return 0;
}