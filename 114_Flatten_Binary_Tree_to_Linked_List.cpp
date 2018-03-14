#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* visitAlongLeftPath(TreeNode* root,stack<TreeNode*>& sk){
    TreeNode* prev = root;
    while(root != NULL){
        if(root->right != NULL) sk.push(root->right);
        root->right = root->left;
        root->left = NULL;
        prev = root;
        root = root->right;
    }
    return prev;
}
void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> sk;
    TreeNode* node = root;
    while(true){
        TreeNode* prev = visitAlongLeftPath(node,sk);
        if(sk.empty()) break;
        node = sk.top(); sk.pop();
        prev->right = node;
    }
}
int main(){
    return 0;
}