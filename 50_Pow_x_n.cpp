#include <iostream>
using namespace std;
// This solution is in reference to the dicuss in LeetCode
double myPow(double x, int n) {
    if(n == INT_MIN){
        n+=2; // no affect for results
    }
    if(n<0){
        x = 1.0/x;
        n *= -1;
    }
    if(n == 0) return 1;
    if(n == 1) return x;
    double half = myPow(x,n/2);
    double ans = half * half;
    if(n%2 == 1) ans *= x;
    return ans;
}
int main(){
    return 0;
}