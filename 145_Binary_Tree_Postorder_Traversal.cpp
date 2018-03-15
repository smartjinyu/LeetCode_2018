#include <iostream>
#include <vector>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void visitAlongLeftPath(stack<TreeNode*>& sk, TreeNode* root){
    while(root != NULL){
        sk.push(root);
        root = root->left;
    }
}
vector<int> postorderTraversal(TreeNode* root) {
    TreeNode* node = root; TreeNode* lastVisited = NULL;
    stack<TreeNode*> sk;
    vector<int> res;
    visitAlongLeftPath(sk,node);
    while(node != NULL && !sk.empty()){
        if(sk.empty()) break;
        node = sk.top();
        if(node->right != NULL && node->right != lastVisited){
            node = node->right;
            visitAlongLeftPath(sk,node);
        }else{
            lastVisited = node;
            res.push_back(node->val);
            sk.pop();
        }
    }
    return res;
}

int main(){
    return 0;
}