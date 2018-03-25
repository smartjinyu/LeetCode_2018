#include <iostream>
#include <vector>
using namespace std;
int integerBreak(int n) {
    static vector<int> res(3,1); // res[i] max product of breaks of i
    if(n < res.size() && res[n] != 0) return res[n];
    for(int i = res.size(); i <= n; i++){
        int ans = 1;
        for(int j = 1; j <= i/2; j++){
            ans = max(ans,max(j,res[j]) * max(i-j,res[i-j]));
        }
        res.push_back(ans);
    }
    return res[n];
    
}

int main(){
    return 0;
}