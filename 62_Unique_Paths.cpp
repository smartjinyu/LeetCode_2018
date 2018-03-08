#include <iostream>
using namespace std;
long long fact[200] = {0};
long long factorial(int n){
    if(fact[n] != 0){
        return fact[n];
    }else{
        long long result = n * factorial(n-1);
        fact[n] = result;
        return result;
    }
}

int uniquePaths(int m, int n) {
    fact[0] = 1;
    // result = (m+n-2)!/(m!*n!);
    m--;n--;
    int a = max(m,n); int b = min(m,n);
    long long result = 1;
    for(int i = a+1; i <= a+b; i++){
        result *= i;
    }
    return result/factorial(b);
}

int main(){
    printf("%d\n",uniquePaths(1,100));
    return 0;
}