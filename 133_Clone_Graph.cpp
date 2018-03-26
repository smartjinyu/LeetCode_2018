#include <iostream>
#include <unordered_map>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> um;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL){return NULL;}
    if(um.find(node) == um.end()){
        um[node] = new UndirectedGraphNode(node->label);
        for(UndirectedGraphNode* neighbor : node->neighbors){
            um[node]->neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return um[node];
}
int main(){
    return 0;
}