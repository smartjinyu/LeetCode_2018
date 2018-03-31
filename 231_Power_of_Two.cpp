#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
bool isPowerOfTwo(int n) {
    if(n <= 0 || (n & (n-1)) != 0) return 0;
    else return 1;
}
int main(){
    return 0;
}