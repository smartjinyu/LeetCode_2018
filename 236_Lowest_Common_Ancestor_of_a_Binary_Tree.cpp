#include <iostream>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || p == root || q == root){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);
    if(left == NULL && right == NULL){
        return NULL;
    }else if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }
}

int main(){
    return 0;
}