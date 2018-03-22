#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* sortedListToBST(ListNode* head) {
    if(head == NULL) return NULL;
    // find the mid
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode* treeHead = new TreeNode(slow->val);
    if(prev != NULL){
        prev->next = NULL;
        treeHead->left = sortedListToBST(head);
        treeHead->right = sortedListToBST(slow->next);  
    }else{
        treeHead->right = sortedListToBST(slow->next);  
    }
    return treeHead;
}
int main(){
    return 0;
}