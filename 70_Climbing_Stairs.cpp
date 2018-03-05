#include <iostream>
using namespace std;
int result[10000] = {0};
int climbStairs(int n) {
    if (n <= 2){
        return n;
    } else if(result[n] != 0){
        return result[n];
    }else{
        int res = climbStairs(n-1) + climbStairs (n-2);
        result[n] = res;
        return res;
    }
}

int main(){
    printf("%d\n",climbStairs(104));
    return 0;
}