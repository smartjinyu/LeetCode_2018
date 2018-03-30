#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;
// This solution is in reference to the solution in LeetCode
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    if(N == 1) return 0;
    // make graph  graph[i] is {j,m} means that there is an directed edge from i to j costing m
    vector<vector<pair<int,int>>> graph(N+1);
    for(auto t : times){
        graph[t[0]].push_back({t[1],t[2]});
    }
    
    // Dijsktra
    vector<int> dist(N+1,INT_MAX);
    vector<int> visited(N+1,0);
    dist[K] = 0;
    auto comp = [] (pair<int,int> a, pair<int,int> b){return a.first > b.first;};
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> heap(comp);
    heap.push({0,K}); // {dist from K, node}
    while(!heap.empty()){
        auto p = heap.top(); heap.pop();
        if(visited[p.second] == 1) continue;
        visited[p.second] = 1;
        for(auto node : graph[p.second]){
            if(dist[node.first] > dist[p.second] + node.second){
                dist[node.first] = dist[p.second] + node.second;
                heap.push({dist[node.first],node.first});
            }
        }
    }
    
    // results
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(dist[i] == INT_MAX) return -1;
        else ans = max(ans,dist[i]);
    }
    return ans;
}

int main(){
    return 0;
}