#include <iostream>
using namespace std;
string getPermutation(int n, int k) {
    static int factorial[10] = {0};
    if(factorial[0] == 0){
        factorial[0] = 1;
        for(int i = 1; i <= 9; i++){
            factorial[i] = i * factorial[i-1];
        }
    }
    int used[10] = {0};
    string res;
    k--;
    int order, digit, seq;
    for(int i = 0; i < n; i++){
        // i is the no. of digit
        order = k / factorial[n-1-i];
        seq = 0;
        for(int j = 1; j <= n; j++){
            if(used[j] != 1){
                if(seq == order){
                    digit = j; break;
                }else{
                    seq++;
                }
            }
        }// find the current digit
        res.push_back('0'+digit);
        used[digit] = 1;
        k -= order * factorial[n-1-i];
    }
    return res;
}
int main(){
    return 0;
}