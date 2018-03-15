#include <iostream>
#include <stack>
class BSTIterator {
public:
    stack<TreeNode*> sk;
    // just like inorder traversal
    BSTIterator(TreeNode *root) {
        pushToStack(root);
    }
    void pushToStack(TreeNode* root){
        while(root != NULL){
            sk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = sk.top(); sk.pop();
        pushToStack(node->right);
        return node->val;
    }
};
