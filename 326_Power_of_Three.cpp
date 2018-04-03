#include <iostream>
#include <climits>
using namespace std;
// This solution is in reference to the disucss in LeetCode
bool isPowerOfThree(int n) {
    return (n > 0) && (1162261467 % n == 0);
}

int main(){
    long long res = 3;
    while(res * 3 < INT_MAX) res *= 3;
    printf("max power of 3 is %lld\n",res);
    return 0;
}