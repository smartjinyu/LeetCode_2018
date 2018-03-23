#include <iostream>
#include <vector>
using namespace std;
int par[1001]; // dis-joint set
void init(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
}
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    init(edges.size());
    vector<int> ans;
    if(edges.size() == 0) return ans;
    for(auto pair : edges){
        int a = find(pair[0]);
        int b = find(pair[1]);
        if(a!=b){
            par[a] = b;
        }else{
            ans = pair;
        }
    }
    return ans;
}
int main(){
    return 0;
}