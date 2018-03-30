#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
int divide(int dividend, int divisor) {
    if(divisor == 0 || dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(dividend == 0) return 0;
    if(divisor == 1) return dividend;
    int sign = 1;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;
    long int adid = labs(dividend);
    long int adis = labs(divisor);
    int ans = 0; long int base = 1; long int temp;
    while(adid >= adis){
        base = 1;
        temp = adis;
        while(base * adis <= adid){
            base = base << 2;
            temp = temp << 2;
        } 
        temp = temp >> 2;
        base = base >> 2;
        ans += base;
        adid -= temp;
    }
    return ans*sign;  
}
int main(){
    return 0;
}