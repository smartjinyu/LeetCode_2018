#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }else{
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
}

int main(){
    TreeNode left1 = TreeNode(2);
    TreeNode right1 = TreeNode(2); TreeNode right2 = TreeNode(3);
    TreeNode root1 = TreeNode(1);
    root1.left = &left1; 
    root1.right = &right1;
    right1.right = &right2;
    printf("%d\n",maxDepth(&root1));
    return 0;
}