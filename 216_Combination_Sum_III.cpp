#include <iostream>
#include <vector>
using namespace std;
void combine(int begin, int k, int n, vector<int>& cur, vector<vector<int>>& res){
    if(cur.size() == k && n == 0){
        res.push_back(cur);
        return;
    }else if(n < begin || cur.size() > k || begin > 9){
        return;
    }else{
        for(int i = begin; i < 10 && i <= n; i++){
            cur.push_back(i);
            combine(i+1,k,n-i,cur,res);
            cur.pop_back();
        }
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> cur;
    combine(1,k,n,cur,res);
    return res;
}
int main(){
    return 0;
}