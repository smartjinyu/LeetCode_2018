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

TreeNode* buildSubTree(vector<int>& postorder,int plo,int phi, vector<int>& inorder,int ilo, int ihi){
    if(phi == plo){
        return NULL;
    }else if(phi - plo == 1){
        return new TreeNode(postorder[phi-1]);
    }else{
        int target = postorder[phi-1];
        int iindex = findInt(inorder,ilo,ihi,target);
        int len = iindex - ilo;
        TreeNode* root = new TreeNode(target);
        root->left = buildSubTree(postorder,plo,plo+len,inorder,ilo,iindex);
        root->right = buildSubTree(postorder,plo+len,phi-1,inorder,iindex+1,ihi);
        return root;
    }

}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() == 0 || inorder.size() != postorder.size()) return NULL;
    return buildSubTree(postorder,0,postorder.size(),inorder,0,inorder.size());
}

int main(){
    return 0;
}