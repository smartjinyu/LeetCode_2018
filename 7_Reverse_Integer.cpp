#include <iostream>
#include <climits>
using namespace std;
// This solution is in refence to the discussion section in LeetCode
int reverse(int x){
    long long res = 0;
    int sign = 1;
    if(x < 0){
        sign = -1;
        x *= -1;
    }
    while(x >= 1){
        res = res * 10 + x % 10;
        x /= 10;
    }
    res *= sign;
    if(res > INT_MAX || res < INT_MIN){
        return 0;
    }else{
        return res;
    }
}
int main(){
    printf("%d\n",reverse(12345554));
    return 0;
}