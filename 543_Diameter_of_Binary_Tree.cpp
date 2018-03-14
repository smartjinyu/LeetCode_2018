#include <iostream>
using namespace std;
// This problem is in reference to the discuss in LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = 0;
int diameter(TreeNode* root){
    if(root == NULL) return 0;
    int left = diameter(root->left);
    int right = diameter(root->right);
    ans = max(ans,left+right+1);
    return max(left,right) + 1;        
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    diameter(root);
    return ans-1;
}

int main(){
    return 0;
}