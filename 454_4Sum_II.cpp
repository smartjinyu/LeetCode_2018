#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// This solution is in reference to the discuss in LeetCode
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int,int> results;
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            results[A[i]+B[j]]++;
        }
    }
    int ans = 0;
    for(int i = 0; i < C.size(); i++){
        for(int j = 0; j < D.size(); j++){
            ans += results[-C[i]-D[j]];
        }
    }
    return ans;

}

int main(){
    int myArrayA[] = {1, 2};
    int myArrayB[] = {-2,-1};
    int myArrayC[] = {-1, 2};
    int myArrayD[] = {0, 2};
    vector<int> A(myArrayA,myArrayA + sizeof(myArrayA)/sizeof(int));
    vector<int> B(myArrayB,myArrayB + sizeof(myArrayB)/sizeof(int));
    vector<int> C(myArrayC,myArrayC + sizeof(myArrayC)/sizeof(int));
    vector<int> D(myArrayD,myArrayD + sizeof(myArrayD)/sizeof(int));
    printf("%d\n",fourSumCount(A,B,C,D));
    return 0;
}