#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    TreeNode* l = root; int lcnt = 0;
    TreeNode* r = root; int rcnt = 0;
    while(l != NULL){
        l = l->left;
        lcnt++;
    }
    while(r != NULL){
        r = r->right;
        rcnt++;
    }
    if(lcnt == rcnt){
        return (int)pow(2,lcnt) - 1;
    }else{
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
}
int main(){
    return 0;
}