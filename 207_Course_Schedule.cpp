#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// This solution is based on the discuss in LeetCode
void makeGraph(vector<pair<int, int>>& prerequisites,vector<unordered_set<int>>& graph){
    for(auto p : prerequisites){
        graph[p.second].insert(p.first);
    }
}

void computeDegree(vector<unordered_set<int>>& graph, vector<int>& degrees){
    // in degree
    for(int i = 0; i < graph.size(); i++){
        for(int j : graph[i]){
            degrees[j]++;
        }
    }
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<unordered_set<int>> graph(numCourses);
    makeGraph(prerequisites,graph);
    vector<int> degrees(numCourses,0);
    computeDegree(graph,degrees);
    for(int i = 0; i < numCourses; i++){
        int j = 0;
        for(; j < numCourses; j++){
            if(degrees[j] == 0) break;
        }
        if(j == numCourses) return false;
        degrees[j] = - 1;
        for(int node : graph[j]) degrees[node]--;
    }
    return true;
}
int main(){
    return 0;
}