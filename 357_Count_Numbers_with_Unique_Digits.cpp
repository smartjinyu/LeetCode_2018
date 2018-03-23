#include <iostream>
using namespace std;
int countNumbersWithUniqueDigits(int n) {
    static int ans[1000];
    ans[0] = 1;
    ans[1] = 10;
    if(n > 10) n = 10;
    if(ans[n] != 0) return ans[n];
    for(int i = 2; i <= n; i++){
        if(ans[i] == 0){
            ans[i] = (ans[i-1] - ans[i-2]) * (11-i) + ans[i-1];
        }
    }
    return ans[n];
}
int main(){
    return 0;
}