#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <typeinfo>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if(s.size() <= 1) return s.size();
    unordered_map<char,int> um; // um[c] is the index of c + 1
    int i = 0, ans = 0; // i is the start index of current substring
    um[s[0]] = 1;
    for(int j = 1; j < s.size(); j++){
        if(um[s[j]] <= i){ // before current substring
            um[s[j]] = j + 1;
        }else{
            ans = max(ans,j - i);
            i = um[s[j]];
            um[s[j]] = j + 1;
        }
    }
    ans = max(ans,(int)s.size() - i);
    return ans;
}

int main(){
    printf("%d\n",lengthOfLongestSubstring("bbbb"));
    return 0;
}