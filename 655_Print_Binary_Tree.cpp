#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printRec(TreeNode* node, int level, int lo, int hi, vector<vector<string>>& res){
    if(node == NULL) return;
    int mid = (lo + hi)/2;
    res[level][mid] = to_string(node->val);
    printRec(node->left,level+1,lo,mid,res);
    printRec(node->right,level+1,mid+1,hi,res);
    
}
int getHeight(TreeNode* node){
    if(node == NULL) return 0;
    return max(getHeight(node->left),getHeight(node->right))+1;
}
vector<vector<string>> printTree(TreeNode* root) {
    int m = getHeight(root);
    int n = (int)pow(2,m)-1;
    vector<vector<string>> res(m,vector<string>(n,""));
    printRec(root,0,0,n,res);
    return res;
        
}
int main(){
    return 0;
}