#include <iostream>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int rangeBitwiseAnd(int m, int n) {
    if(m >= n) return m;
    else{
        return rangeBitwiseAnd(m/2,n/2)*2;
    }
}
int main(){
    return 0;
}