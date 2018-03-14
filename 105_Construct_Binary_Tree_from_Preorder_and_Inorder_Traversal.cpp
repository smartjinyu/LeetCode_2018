#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findInt(vector<int>& nums, int lo, int hi, int target){
    for(int i = lo; i < hi; i++){
        if(nums[i] == target) return i;
    }
    return -1;
}

TreeNode* buildSubTree(vector<int>& preorder,int plo,int phi, vector<int>& inorder,int ilo, int ihi){
    if(phi == plo){
        return NULL;
    }else if(phi - plo == 1){
        return new TreeNode(preorder[plo]);
    }else{
        int target = preorder[plo];
        int iindex = findInt(inorder,ilo,ihi,target);
        int len = iindex - ilo;
        TreeNode* root = new TreeNode(target);
        root->left = buildSubTree(preorder,plo+1, plo+len+1,inorder,ilo,iindex);
        root->right = buildSubTree(preorder,plo+len+1,phi,inorder,iindex+1,ihi);
        return root;
    }
    
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 || preorder.size() != inorder.size()) return NULL;
    return buildSubTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    
}

int main(){
    return 0;
}