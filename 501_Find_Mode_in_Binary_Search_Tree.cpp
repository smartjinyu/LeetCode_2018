#include <iostraem>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This solution is in reference to the discuss in LeetCode
vector<int> findMode(TreeNode* root) {
    stack<TreeNode*> sk;
    TreeNode* node = root;
    vector<int> res;
    if(node == NULL) return res;
    int prev, cnt = 0, maxcnt = 0;
    bool first = true;
    while(true){
        while(node != NULL){
            sk.push(node);
            node = node->left;
        }
        if(sk.empty()) break;
        node = sk.top(); sk.pop();
        if(first){
            prev = node->val; cnt++; first = false;
        }else if(node->val == prev){
            cnt++;
        }else{
            if(cnt == maxcnt){
                res.push_back(prev);
            }else if(cnt > maxcnt){
                maxcnt = cnt;
                res.clear();
                res.push_back(prev);
            }
            cnt = 1;
            prev = node->val;
        }
        node = node->right;
    }
    if(cnt == maxcnt){
        res.push_back(prev);
    }else if(cnt > maxcnt){
        res.clear();
        res.push_back(prev);
    }
    return res;
}

int main(){
    return 0;
}