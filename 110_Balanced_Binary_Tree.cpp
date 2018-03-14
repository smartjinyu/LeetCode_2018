#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    if(left == -1 || right == -1){
        return -1;
    }else if(abs(left-right) > 1){
        return -1;
    }else{
        return max(left,right) + 1;
    }
}
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    int left = height(root->left);
    int right = height(root->right);
    return left != -1 && right!= -1 && abs(left - right) <= 1;
}
int main(){
    return 0;
}