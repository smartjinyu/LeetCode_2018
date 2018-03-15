#include <iostream>
using namespace std;

int numTrees(int n) {
    static int ans[10000] = {0};
    if(n == 0 || n == 1){
        return 1;
    }else if(ans[n]!=0){
        return ans[n];
    }else{
        int res = 0;
        for(int i = 0; i < n; i++){
            res += numTrees(i) * numTrees(n-1-i);
        }
        ans[n] = res;
        return ans[n];
    }
}
int main(){
    printf("%d\n",numTrees(1000));
    return 0;
}