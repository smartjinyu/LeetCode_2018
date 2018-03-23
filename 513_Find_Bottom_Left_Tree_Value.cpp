#include <iostream>
#include <vector>
using namespace std;
void levelTraversal(TreeNode* node, int level, vector<int>& leftVal){
    if(node == NULL) return;
    if(level == leftVal.size()){
        leftVal.push_back(node->val);
    }
    levelTraversal(node->left,level+1,leftVal);
    levelTraversal(node->right,level+1,leftVal);
    
}
int findBottomLeftValue(TreeNode* root) {
    vector<int> leftVal;
    levelTraversal(root,0,leftVal);
    return leftVal[leftVal.size()-1];
    
}
int main(){
    return 0;
}