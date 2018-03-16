#include <iostream>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int robRec(TreeNode* node, int used){
    if(node == NULL) return 0;
    if(used == 1){
        return robRec(node->left,0) + robRec(node->right,0);
    }else{
        int num1 = node->val + robRec(node->left,1) + robRec(node->right,1);
        int num2 = robRec(node->left,0) + robRec(node->right,0);
        return max(num1,num2);
    }
}
int rob(TreeNode* root) {
    return robRec(root,0);
}

int main(){
    return 0;
}