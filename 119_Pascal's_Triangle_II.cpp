#include <iostream>
#include <vector>
using namespace std;
vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1,1);
    if(rowIndex == 0){
        return ans;
    }else{
        for(int i = 1; i <= rowIndex; i++){
            long res = (long)ans[i-1] * (rowIndex - i + 1)/i;
            ans[i] = res;
        }
        return ans;
    }
}
int main(){
    return 0;
}