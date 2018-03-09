#include <iostream>
using namespace std;
int titleToNumber(string s) {
    if(s.size() == 0){
        return 0;
    }
    int ans = 0;
    int base = 1;
    for(int i = s.size() - 1; i >= 0; i--){
        ans += ((int)s[i] - 64) * base;
        base *= 26;
    }
    return ans;
}

int main(){
    string str = "AA";
    printf("%d\n",titleToNumber(str));
    return 0;
}