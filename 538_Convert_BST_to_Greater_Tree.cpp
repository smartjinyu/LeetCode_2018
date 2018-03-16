#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongRightPath(TreeNode* node, stack<TreeNode*>& sk){
    while(node != NULL){
        sk.push(node);
        node = node->right;
    }
}
TreeNode* convertBST(TreeNode* root) {
    // inverse inorder traversal
    stack<TreeNode*> sk;
    TreeNode* node = root;
    int sum = 0, temp = 0;
    while(true){
        visitAlongRightPath(node,sk);
        if(sk.empty()) break;
        node = sk.top(); sk.pop();
        temp = node->val; node->val += sum; sum += temp;
        node = node->left;
    }
    return root;
}

int main(){
    return 0;
}