#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongLeftPath(stack<TreeNode*>& sk,vector<int>& res,TreeNode* root){
    while(root != NULL){
        res.push_back(root->val);
        if(root->right != NULL) sk.push(root->right);
        root = root->left;
    }
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    stack<TreeNode*> sk;
    TreeNode* node = root;
    while(true){
        visitAlongLeftPath(sk,res,node);
        if(sk.empty()) break;
        node = sk.top();
        sk.pop();
    }
    return res;
}
int main(){
    return 0;
}