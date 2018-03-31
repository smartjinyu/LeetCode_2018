#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = 0;
void levelTraversal(TreeNode* node, int pos, int level, vector<int>& res){
    if(node == NULL) return;
    if(level == res.size()) {
        res.push_back(pos);
    } else {
        ans = max(ans,pos - res[level]);
    }
    levelTraversal(node->left,2*pos,level+1,res);
    levelTraversal(node->right,2*pos+1,level+1,res);
}
int widthOfBinaryTree(TreeNode* root) {
    ans = 0;
    if(root == NULL) return 0;
    vector<int> res;
    levelTraversal(root,0,0,res);
    return ans+1;
}
int main(){
    return 0;
}