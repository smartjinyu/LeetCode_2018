/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeRec(TreeNode* node, vector<string>& series){
        // preorder traversal
        if(node == NULL){
            series.push_back("#");
            return;
        }else{
            series.push_back(to_string(node->val));
            serializeRec(node->left,series);
            serializeRec(node->right,series);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> series;
        serializeRec(root, series);
        string ans;
        if(series.size() == 0){
            return ans;
        }else{
            for(int i = 0; i < series.size(); i++){
                ans += series[i];
                ans += ",";
            }
            return ans;
            // "1,2,#,#,3,"
        }
    }
    TreeNode* deserializeRec(string& data, int& start){
        int begin = start;
        if(begin == data.size()){
            return NULL;
        }
        int end = 0;
        for(int i = begin; i < data.size(); i++){
            if(data[i] == ','){
                end = i;
                break;
            }
        }
        start = end + 1;
        if(end - begin == 1 && data[begin] == '#'){            
            return NULL;
        }else{
            int val = stoi(data.substr(begin,end - begin));
            TreeNode* node = new TreeNode(val);
            node->left = deserializeRec(data,start);
            node->right = deserializeRec(data,start);
            return node;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        int begin = 0;
        return deserializeRec(data,begin);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));