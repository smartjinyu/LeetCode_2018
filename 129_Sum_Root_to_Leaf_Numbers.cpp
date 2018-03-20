#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumRec(TreeNode* node, int cur, int& ans){
    if(node == NULL) return;
    cur = cur*10 + node->val;
    if(node->left == NULL && node->right == NULL){
        ans += cur;
    }else{
        sumRec(node->left,cur,ans);
        sumRec(node->right,cur,ans);
    }
}
int sumNumbers(TreeNode* root) {
    if(root == NULL) return 0;
    int res = 0;
    sumRec(root,0,res);
    return res;
}
int main(){
return 0;
}