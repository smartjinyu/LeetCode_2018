#include <iostream>
#include <cmath>
using namespace std;
int hammingDistance(int x, int y) {
    int res = x^y;
    int ans = 0;
    while(res > 0){
        res -= floor(pow(2,floor(log2(res))));
        ans++;
    }
    return ans;
}

int main(){
    printf("%d\n",hammingDistance(2,2));
    return 0;
}