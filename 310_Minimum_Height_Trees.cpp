#include <vector>
#include <unordered_set>
using namespace std;
// This solution is in reference to the discuss in LeetCode
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> ans(1,0);
    if(edges.size() == 0) return ans;
    vector<unordered_set<int>> graph(n);
    for(auto p : edges){
        graph[p.first].insert(p.second);
        graph[p.second].insert(p.first);
    }
    
    vector<int> sk1;
    vector<int> sk2;
    vector<int>* skp1 = &sk1; // current stack
    vector<int>* skp2 = &sk2; // next stack
    for(int i = 0; i < n; i++){
        if(graph[i].size() == 1){
            skp1->push_back(i);
        }
    }
    while(true){
        for(int i : *skp1){
            for(auto node : graph[i]){
                graph[node].erase(i);
                if(graph[node].size() == 1) skp2->push_back(node);
            }
        }
        if(skp2->size() == 0) return *skp1;
        skp1->clear();
        swap(skp1,skp2);
    }
}
int main(){
    return 0;
}