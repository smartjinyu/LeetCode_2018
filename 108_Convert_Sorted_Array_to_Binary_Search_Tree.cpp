#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildBST(vector<int>& nums,int lo, int hi){
    if(hi == lo){
        return NULL;
    }else if(hi - lo == 1){
        return new TreeNode(nums[lo]);
    }else if(hi - lo == 2){
        TreeNode* node1 = new TreeNode(nums[lo+1]);
        TreeNode* node2 = new TreeNode(nums[lo]);
        node1->left = node2;
        return node1;
    }else if(hi - lo == 3){
        TreeNode* node1 = new TreeNode(nums[lo+1]);
        TreeNode* node2 = new TreeNode(nums[lo]);
        TreeNode* node3 = new TreeNode(nums[lo+2]);
        node1->left = node2; node1->right = node3;
        return node1;
    }else{
        int mid = (lo + hi)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = buildBST(nums,lo,mid);
        TreeNode* right = buildBST(nums,mid+1,hi);
        root->left = left; root->right=right;
        return root;            
    }
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums,0,nums.size());
}

int main(){
    return 0;
}