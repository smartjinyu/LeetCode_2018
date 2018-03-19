#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int calSum(TreeNode* node, unordered_map<int,int>& um){
    if(node == NULL) return 0;
    int sum = node->val + calSum(node->left,um) + calSum(node->right,um);
    um[sum]++;
    return sum;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res; int maxMode = -1;
    if(root == NULL) return res;
    unordered_map<int,int> um; // {sum,times}
    calSum(root,um);
    for(auto it = um.begin(); it != um.end(); ++it){
        if(it->second > maxMode){
            res.clear();
            res.push_back(it->first);
            maxMode = it->second;
        }else if(it->second == maxMode){
            res.push_back(it->first);
        }
    }
    return res;
}
int main(){
    return 0;
}