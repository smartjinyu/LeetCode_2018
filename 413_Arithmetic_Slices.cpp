#include <iostream>
#include <vector>
using namespace std;
int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() <= 2) return 0;
    int j = 0;
    int ans = 0;
    for(int i = 0; i < A.size() - 2;){
        int diff =  A[i+1] - A[i];
        j = i+2;
        while(j < A.size() && A[j] - A[j-1] == diff) j++;
        int len = j - i;
        ans += (len-2) * (len- 1)/2;
        i = j - 1;
    }
    return ans;
}
int main(){
    return 0;
}