#include <iostream>
using namespace std;
bool isAnagram(string s, string t) {
    int cnt[26] = {0};
    for(char c : s){
        cnt[(int)c-97]++;
    }
    for(char c : t){
        cnt[(int)c-97]--;
    }
    for(int num : cnt){
        if(num != 0){
            return false;
        }
    }
    return true;
}

int main(){
    printf("%d\n",isAnagram("aabcc","bacc"));
    return 0;
}