#include <iostream>
#include <cmath>
using namespace std;
int trailingZeroes(int n) {
    if(n < 5){
        return 0;
    }
    int max = floor(log(n)/log(5));
    int ans = 0;
    for (int i = 1; i <= max; i++){
        ans += floor(n/pow(5,i));
    }
    return ans;

}

int main(){
    printf("%d\n",trailingZeroes(50));
    return 0;
}