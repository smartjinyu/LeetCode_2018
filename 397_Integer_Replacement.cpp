#include <iostream>
#include <climits>
using namespace std;
int integerReplacement(int n) {
    if(n == 1) return 0;
    if(n == INT_MAX) return 32;
    if(n % 2 == 0) return 1+integerReplacement(n/2);
    else return min(integerReplacement(n+1),integerReplacement(n-1)) + 1;
}
int main(){
    return 0;
}