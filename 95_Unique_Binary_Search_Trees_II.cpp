#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateRec(int lo, int hi){
    // generate binary tree int [lo,hi)
    vector<TreeNode*> ans;
    if(lo == hi){
        return ans;
    }else{
        for(int i = lo; i < hi; i++){                
            vector<TreeNode*> lefts = generateRec(lo,i);
            vector<TreeNode*> rights = generateRec(i+1,hi);
            if(lefts.size() == 0 && rights.size() == 0){
                TreeNode* node = new TreeNode(i);
                ans.push_back(node);
            }else if(lefts.size() == 0){
                for(TreeNode* r : rights){
                    TreeNode* node = new TreeNode(i);
                    node->right = r;
                    ans.push_back(node);
                }
            }else if(rights.size() == 0){
                for(TreeNode* l : lefts){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    ans.push_back(node);
                }
            }else{
                for(TreeNode* l : lefts){
                    for(TreeNode* r : rights){
                        TreeNode* node = new TreeNode(i);
                        node->left = l;
                        node->right = r;
                        ans.push_back(node);
                    }
                }
            }
        }
        return ans;
    }
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ans = generateRec(1,n+1);
    return ans;
}

int main(){
    return 0;
}