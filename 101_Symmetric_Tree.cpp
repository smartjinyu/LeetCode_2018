#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isSymmetricTwoTrees(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    } else if (root1 == NULL || root2 == NULL){
        return false;
    } else {
        return (root1->val == root2->val) && isSymmetricTwoTrees(root1->left,root2->right) && isSymmetricTwoTrees(root1->right,root2->left);
    }

}
bool isSymmetric(TreeNode* root) {
    if(root == NULL){
        return true;
    }else{
        return isSymmetricTwoTrees(root->left,root->right);
    }
    
}

int main(){
    TreeNode left1 = TreeNode(2);
    TreeNode right1 = TreeNode(2);
    TreeNode root1 = TreeNode(1);
    root1.left = &left1; 
    root1.right = &right1;
    printf("%d\n",isSymmetric(&root1));
    return 0;
}