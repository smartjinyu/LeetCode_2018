#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
bool isPowerOfFour(int num) {
    if(num <= 0 || (num & (num-1)) != 0 || (num - 1) % 3 != 0) return 0;
    else return 1;
}
int main(){
    return 0;
}