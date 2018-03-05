#include <iostream>
using namespace std;
int lengthOfLastWord(string s) {
    int len = 0;
    while (s[s.size() - 1 - len] == ' '){
        len ++;
    }
    for(int i = 0; i < s.size() - len; i++){
        if (s[s.size() - len -i-1] == ' '){
            return i;
        }
    }
    return s.size() - len;
}

int main(){
    printf("%d\n",lengthOfLastWord("Hello    "));
    return 0;
}