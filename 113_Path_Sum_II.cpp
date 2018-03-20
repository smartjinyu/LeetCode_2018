#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumRec(TreeNode* node, int sum, int curSum, vector<int> cur,vector<vector<int>>& res){
    if(node == NULL) return;
    curSum += node->val;
    cur.push_back(node->val);
    if(node->left == NULL && node->right == NULL){
        if(curSum == sum) res.push_back(cur);
    }else{
        sumRec(node->left,sum,curSum,cur,res);
        sumRec(node->right,sum,curSum,cur,res);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    vector<int> cur;
    sumRec(root,sum,0,cur,res);
    return res;
    
}
int main(){
    return 0;
}