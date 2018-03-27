#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelTraversal(TreeNode* node, int level, vector<vector<int>>& ans){
    if(node == NULL) return;
    if(level == ans.size()) ans.push_back(vector<int>(1,node->val));
    else ans[level].push_back(node->val);
    levelTraversal(node->left,level+1,ans);
    levelTraversal(node->right,level+1,ans);

}
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    levelTraversal(root,0,ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    return 0;
}