#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int numSquares(int n) {
    static vector<int> perfect(0);
    if(n < perfect.size()){
        return perfect[n];
    }
    int res = n;
    for(int i = 1; i*i <= n; i++){
        res = min(res,1 + numSquares(n-i*i));
    }
    perfect.push_back(res);
    return res;
}

int main(){
    printf("%d\n",numSquares(12));
    return 0;
}