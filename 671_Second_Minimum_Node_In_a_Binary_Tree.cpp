#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findLarger(TreeNode* node, int val){
    // find the most closet value > val, if not exists return -1
    if(node == NULL) return -1;
    if(node->val > val){
        return node->val;
    }else{
        int n1 = findLarger(node->left,val);
        int n2 = findLarger(node->right,val);
        if(n1 == -1 && n2 == -1){
            return -1;
        }else if(n1 == -1){
            return n2;
        }else if(n2 == -1){
            return n1;
        }else{
            return min(n1,n2);
        }
    }
    
    
}
int findSecondMinimumValue(TreeNode* root) {
    if(root == NULL) return -1;
    return findLarger(root,root->val);
}

int main(){
    return 0;
}