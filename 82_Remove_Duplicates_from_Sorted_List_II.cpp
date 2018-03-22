#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* node = head;
    ListNode* fast = NULL;
    ListNode* tempHead = new ListNode(head->val - 1);
    tempHead->next = head;
    ListNode* prev = tempHead;
    while(node != NULL){
        fast = node->next;
        while(fast != NULL && fast->val == node->val) fast = fast->next;
        if(fast == node->next){
            prev = node;
            node = node->next;
        }else{
            prev->next = fast;
            node = fast;
        }
    }
    return tempHead->next;
    
}
int main(){
    return 0;
}