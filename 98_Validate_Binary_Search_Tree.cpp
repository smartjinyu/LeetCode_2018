#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValid(TreeNode* root,long int lo,long int hi){
    if(root == NULL){
        return true;
    }else{
        return (root->val > lo) && (root->val < hi) && isValid(root->right,root->val,hi) && isValid(root->left,lo,root->val);
    }

}
bool isValidBST(TreeNode* root) {
    return isValid(root,LONG_MIN,LONG_MAX);
}

int main(){
    return 0;
}