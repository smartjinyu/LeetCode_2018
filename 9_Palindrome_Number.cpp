#include <iostream>
using namespace std;
bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x/10 == 0) return true;
    if(x % 10 == 0) return false;
    int y = 0;
    while(x > y){
        y = y * 10 + x % 10;
        x /= 10;
    }
    return x == y/10 || x == y;
}
int main(){
    return 0;
}