#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void traversal(TreeNode* node, int level, vector<vector<int>>& res){
    if(node == NULL) return;
    if(level == res.size()){
        vector<int> cur;
        res.push_back(cur);
    }
    res[level].push_back(node->val);
    traversal(node->left,level+1,res);
    traversal(node->right,level+1,res);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == NULL) return res;
    traversal(root, 0, res);
    for(int i = 0; i < res.size(); i++){
        if(i%2 == 1){
            reverse(res[i].begin(),res[i].end());
        }
    }
    return res;
}
int main(){
    return 0;
}