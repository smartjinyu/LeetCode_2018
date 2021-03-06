#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    else if(root->left == NULL){
        return 1 + minDepth(root->right);            
    }else if(root->right == NULL){
        return 1 + minDepth(root->left); 
    }else{
        return 1 + min(minDepth(root->left),minDepth(root->right)); 
    }
}

int main(){
    return 0;
}