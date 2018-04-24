#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void getPath(TreeNode* node, vector<int>& cur, vector<string>& ans){
    if(node->left == NULL && node->right == NULL){
        cur.push_back(node->val);
        if(cur.size() == 0){
            return;
        }else if(cur.size() == 1){
            ans.push_back(to_string(cur[0]));
        }else{
            string str;
            str.append(to_string(cur[0]));
            for(int i = 1; i < cur.size(); i++){
                str.append("->");
                str.append(to_string(cur[i]));
            }
            ans.push_back(str);
        }
    }else if(node->left == NULL){
        cur.push_back(node->val);
        getPath(node->right,cur,ans);
        cur.pop_back();
    }else if(node->right == NULL){
        cur.push_back(node->val);
        getPath(node->left,cur,ans);
        cur.pop_back();
    }else{
        cur.push_back(node->val);
        getPath(node->left,cur,ans);
        cur.pop_back();
        getPath(node->right,cur,ans);
        cur.pop_back();
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root == NULL) return ans;
    vector<int> cur;
    getPath(root,cur,ans);
    return ans;
}
int main(){
    return 0;
}