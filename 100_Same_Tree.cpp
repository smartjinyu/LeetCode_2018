#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL){
        return true;
    }else if (p == NULL || q == NULL){
        return false;
    }else{
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
}

int main(){
    TreeNode left1 = TreeNode(2); TreeNode left2 = TreeNode(1);
    TreeNode right1 = TreeNode(3); TreeNode right2 = TreeNode(3);
    TreeNode root1 = TreeNode(1); TreeNode root2 = TreeNode(1);
    root1.left = &left1; root2.left = &left2;
    root1.right = &right1; root2.right = &right2;
    printf("%d\n",isSameTree(&root1,&root2));
    return 0;
}