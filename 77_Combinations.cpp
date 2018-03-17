#include <iostream>
#include <vector>
using namespace std;
void combine(int begin, int n, int k, vector<int>& cur, vector<vector<int>>& res){
    if(cur.size() == k){
        res.push_back(cur);
        return;
    }else{
        for(int i = begin; i <= n; i++){
            cur.push_back(i);
            combine(i+1,n,k,cur,res);
            cur.pop_back();
        }
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    combine(1,n,k,cur,res);
    return res;
}
int main(){
    return 0;
}