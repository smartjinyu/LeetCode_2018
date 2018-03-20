#include <iostream>
using namespace std;
int myPow(int x, int n) {
    // n >= 0;
    if(n == 0) return 1;
    if(n == 1) return x;
    int half = myPow(x,n/2) % 1337;
    int ans = (half * half) % 1337 ;
    if(n%2 == 1) ans *= x;
    return ans % 1337;
}

int superPow(int a, vector<int>& b) {
    vector<int> timesTen(b.size(),0);
    timesTen[0] = a % 1337;
    for(int i = 1; i < b.size(); i++){
        timesTen[i] = myPow(timesTen[i-1],10);
    }
    int ans = 1;
    for(int i = 0; i < b.size(); i++){
        ans *= myPow(timesTen[i],b[b.size() - i - 1]);
        ans %= 1337;
    }
    return ans;
        
}
int main(){
    return 0;
}