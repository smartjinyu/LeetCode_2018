#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL) return NULL;
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(){
    return 0;
}