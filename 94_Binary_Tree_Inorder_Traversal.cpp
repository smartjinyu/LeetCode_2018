#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongLeftPath(TreeNode* root, stack<TreeNode*>& sk){
    while(root != NULL){
        sk.push(root);
        root = root->left;
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> sk;
    if(root == NULL) return ans;
    TreeNode* node = root;
    while(true){
        visitAlongLeftPath(node,sk);
        if(sk.empty()) break;
        node = sk.top(); sk.pop();
        ans.push_back(node->val);
        node = node->right;
    }
    return ans;
    
}
int main(){
    return 0;
}