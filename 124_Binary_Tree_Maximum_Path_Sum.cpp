struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// This solution is in reference to the discuss in LeetCode

int maxSum = INT_MIN;
int maxSumRec(TreeNode* root){
    // return maxPathSum whose starting node is root
    if(root == NULL) return 0;
    int l = max(0, maxSumRec(root->left));
    int r = max(0, maxSumRec(root->right));
    maxSum = max(maxSum, root->val + l + r);
    return max(l,r) + root->val;
}

int maxPathSum(TreeNode* root) {
    // return maxPathSum whose starting node is root
    if(root == NULL) return 0;
    maxSum = INT_MIN;
    maxSumRec(root);
    return maxSum;
}

int main(){
    return 0;
}
