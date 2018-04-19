#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumRec(TreeNode* root, int sum, int curSum, vector<int>& res, vector<vector<int>>& ans){
    if(root == NULL) sreturn;
    curSum += root->val;
    res.push_back(root->val);
    if(root->left == NULL && root->right == NULL){
        if(curSum == sum) ans.push_back(res);
    }else{
        sumRec(root->left,sum,curSum,res,ans);
        sumRec(root->right,sum,curSum,res,ans);
    }
    res.pop_back();
    curSum -= root->val;
    
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    vector<int> res;
    sumRec(root,sum,0,res,ans);
    return ans;
}
int main(){
    return 0;
}