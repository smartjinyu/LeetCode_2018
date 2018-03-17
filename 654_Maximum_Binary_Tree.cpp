#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildRec(vector<int>& nums, int lo, int hi){
    // build from nums[lo,hi)
    if(hi <= lo){
        return NULL;
    }else if(hi - lo == 1){
        return new TreeNode(nums[lo]);
    }else{
        int maxNum = nums[lo], index = lo;
        for(int i = lo + 1; i < hi; i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(maxNum);
        node->left = buildRec(nums,lo,index);
        node->right = buildRec(nums,index+1,hi);
        return node;
    }
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildRec(nums,0,nums.size()); 
}
int main(){
    return 0;
}