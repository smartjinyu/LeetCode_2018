#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
void makeGraph(vector<pair<int, int>>& prerequisites, vector<unordered_set<int>>& graph){
    for(auto p : prerequisites){
        graph[p.second].insert(p.first);
    }
}
void computeDegrees(vector<unordered_set<int>>& graph, vector<int>& degrees){
    // compute in degree
    for(auto us : graph){
        for(int num : us){
            degrees[num]++;
        }
    }
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ans;
    vector<int> emp; // empty result
    if(numCourses == 0) return ans;
    if(numCourses == 1){
        ans.push_back(0);
        return ans;
    }
    vector<unordered_set<int>> graph(numCourses);
    makeGraph(prerequisites, graph);
    vector<int> degrees(numCourses, 0);
    computeDegrees(graph,degrees);
    for(int i = 0; i < numCourses; i++){
        int j = 0;
        for(;j < numCourses; j++){
            if(degrees[j] == 0){
                ans.push_back(j);
                break;
            }
        }
        if(j == numCourses) return emp;
        degrees[j] = -1;
        for(int num : graph[j]) degrees[num]--;
    }
    return ans;
}
int main(){
    return 0;
}