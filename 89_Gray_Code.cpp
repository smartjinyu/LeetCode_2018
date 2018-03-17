#include <iostream>
#include <vector>
using namespace std;
vector<int> grayCode(int n) {
    vector<int> ans;
    ans.push_back(0);
    if(n == 0) return ans;
    ans.push_back(1);
    int base = 2;
    for(int i = 1; i < n; i++){
        int temp = ans.size();
        for(int j = 1; j <= base; j++){
            ans.push_back(base + ans[temp - j]);
        }
        base *= 2;
    }
    return ans;
}

int main(){
    return 0;
}
