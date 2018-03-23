#include <iostream>
#include <vector>
using namespace std;
int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> ans(n,0);
    ans[0] = 1;
    vector<int> pointer(primes.size(),0);
    int res = INT_MAX;
    for(int i = 1; i < n; i++){
        res = INT_MAX;
        for(int j = 0; j < primes.size(); j++){
            res = min(res,ans[pointer[j]] * primes[j]);
        }
        for(int j = 0; j < primes.size(); j++){
            if(res == ans[pointer[j]] * primes[j]){
                pointer[j]++;
            }
        }
        ans[i] = res;
    }
    return ans[n-1];
    
}
int main(){
    return 0;
}