#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
void reverse(string &s,int i, int j){
    // reverse contents in [i,j]
    while(i < j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++; j--;
    }
}
void reverseWords(string &s) {
    if(s.size() == 0) return;
    int i = 0, j = 0, wordcnt = 0;
    // i is curIndex, j is the index without extra space
    while(i < s.size()){
        while(i < s.size() && s[i] == ' ') i++; // skip the leading zero
        if(i == s.size()) break;
        if(wordcnt != 0) s[j++] = ' ';
        int lo = j;
        while(i < s.size() && s[i] != ' '){
            s[j++] = s[i++];
        }
        wordcnt++;
        reverse(s,lo,j-1);
    }
    reverse(s,0,j-1);
    s = s.substr(0,j);
}
int main(){
    return 0;
}