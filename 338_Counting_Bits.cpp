#include <iostream>
#include <vector>
using namespace std;
vector<int> countBits(int num) {
    vector<int> ans;
    ans.push_back(0); // 0
    if(num == 0) return ans;
    ans.push_back(1); // 1
    int base = 2; int i = 2;
    while(i <= num){
        while(i < 2*base && i <= num){
            ans.push_back(ans[i-base]+1);
            i++;
        }
        base *= 2;
    }
    return ans;
}

int main(){
    vector<int> ans = countBits(1);
    for(int num : ans) printf("%d ",num);
    return 0;
}