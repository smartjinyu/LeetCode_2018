#include <iostream>
using namespace std;
int firstUniqChar(string s) {
    int cnt[26] = {0};
    for(char c : s){
        cnt[(int)c - 'a']++;
    }
    for(int i = 0; i < s.size(); i++){
        if(cnt[(int)s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("%d\n",firstUniqChar("leetcode"));
    return 0;
}