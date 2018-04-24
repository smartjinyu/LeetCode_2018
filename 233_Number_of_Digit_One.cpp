#include <iostream>
#include <vector>
using namespace std;
int countDigitOne(int n) {
    if(n <= 0) return 0;
    if(n < 10) return 1;
    int digit = log10(n);
    vector<int> num(digit + 1,0); // num[i] = number of 1 from 0 to 99..9 = 9 * (10^i + 10^(i-1) + ... + 10^0)
    // 0 1 20 300 4000 50000
    int base = 1;
    for(int i = 1; i <= digit; i++){
        num[i] = base + 10 * num[i-1];
        base *= 10;
    }
    int ans = 0;
    while(n >= 10){
        digit = log10(n);
        base = rint(pow(10,digit));
        ans += num[digit];
        if(n >= 2* base){
            ans += (base + num[digit] * (n/base-1));
            n -= n/base * base;
        }else{
            n -= base;
            ans += (n+1);
        }
    }
    if(n >= 1) ans += 1;
    return ans;
}
 int main(){
     return 0;
 }