#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* prev = head; ListNode* cur = head->next;
    while(cur != NULL){
        while(cur != NULL && cur->val == prev->val) cur = cur->next;
        prev->next = cur;
        prev = cur;
    }
    return head;
    
}
int main(){
    return 0;
}