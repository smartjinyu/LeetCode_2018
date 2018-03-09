#include <iostream>
using namespace std;
struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connectTri(TreeLinkNode *head){
    // connect a triangle block
    if(head->left == NULL){
        return;
    }
    head->left->next = head->right;
    if(head->next != NULL){
        head->right->next = head->next->left;
    }else{
        head->right->next = NULL;
    }
    connectTri(head->left);
    connectTri(head->right);
}
void connect(TreeLinkNode *root) {
    if(root == NULL){
    }else if(root->left == NULL){
        root->next = NULL;
    }else{
        root->next = NULL;
        root->left->next = root->right;
        root->right->next = NULL;
        connectTri(root->left);
        connectTri(root->right);
    }
}

int main(){
    return 0;
}