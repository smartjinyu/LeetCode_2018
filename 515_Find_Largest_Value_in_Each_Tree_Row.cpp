#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> qe; qe.push(root);
    int curLevel = 1, nextLevel = 0, curMax = -INT_MAX-1;
    while(!qe.empty()){
        TreeNode* node = qe.front(); qe.pop();
        if(curLevel > 0){
            curMax = max(curMax,node->val);
            curLevel--;
        }
        if(node->left != NULL) {qe.push(node->left); nextLevel++;}
        if(node->right != NULL) {qe.push(node->right); nextLevel++;}
        if(curLevel == 0){
            curLevel = nextLevel;
            nextLevel = 0;
            ans.push_back(curMax);
            curMax = -INT_MAX-1;
        }
    }
    return ans;
}

int main(){
    return 0;
}