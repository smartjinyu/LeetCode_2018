#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelTraversal(TreeNode* node, int level, vector<int>& res){
    if(node == NULL) return;
    if(level == res.size()){
        res.push_back(node->val);
    }else{
        res[level] = node->val;
    }
    levelTraversal(node->left,level+1,res);
    levelTraversal(node->right,level+1,res);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    levelTraversal(root,0,res);
    return res;
}
int main(){
    return 0;
}