#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if(root == NULL) return;
    TreeLinkNode* node = root; // current node
    TreeLinkNode* head = NULL; // head of child nodes
    TreeLinkNode* prev = NULL; // prev of child node
    while(node != NULL){
        while(node != NULL){
            if(node->left != NULL || node->right != NULL){
                if(head == NULL){
                    if(node->left == NULL){
                        head = node->right;
                        prev = node->right;
                    }else{
                        head = node->left;
                        prev = node->left;
                        if(node->right != NULL){
                            prev->next = node->right;
                            prev = prev->next;
                        }
                    }
                }else{
                    if(node->left == NULL){
                        prev->next = node->right;
                        prev = prev->next;
                    }else{
                        prev->next = node->left;
                        prev = prev->next;
                        if(node->right != NULL){
                            prev->next = node->right;
                            prev = prev->next;
                        }
                    }
                }
            }
            node = node->next;
        }
        node = head;
        prev = NULL;
        head = NULL;
    }
}
int main(){
    return 0;
}