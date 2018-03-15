#include <iostream>
#include <stack>
using namespace std;
// This is a naive solution using inorder traversal, if you have better solution, please tell me.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongLeftPath(TreeNode* node, stack<TreeNode*>& sk){
    while(node != NULL){
        sk.push(node);
        node = node->left;
    }
}
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    TreeNode* node = root;
    stack<TreeNode*> sk;
    while(true){
        visitAlongLeftPath(node,sk);
        if(sk.empty()) break;
        node = sk.top(); sk.pop();
        cnt++; 
        if(cnt == k) return node->val;
        node = node->right;
    }
    return -1;
}
int main(){
    return 0;
}