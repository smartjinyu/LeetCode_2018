#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void traversal(TreeNode* node, int level, vector<vector<int>>& res){
    if(node == NULL) return;
    if(level == res.size()){
        vector<int> cur;
        res.push_back(cur);
    }
    res[level].push_back(node->val);
    traversal(node->left,level+1,res);
    traversal(node->right,level+1,res);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    traversal(root, 0, res);
    return res;
}
int main(){
    return 0;
}