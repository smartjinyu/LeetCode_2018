#include <iostream>
#include <vector>
using namespace std;
int countPrimes(int n) {
    vector<int> flag(n,0);
    for (int i = 2; i < n; i++){
        if (flag[i] != -1){
            int j = i + i;
            while(j < n){
                flag[j] = -1;
                j += i;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++){
        ans += (flag[i] == 0);
    }
    return ans;
}

int main(){
    printf("%d\n",countPrimes(30));
    return 0;
}