#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL) return head;
    if(k == 0) return head;
    int len = 0;
    ListNode* node = head;
    while(node != NULL){
        node = node->next;
        len++;
    }
    k = k % len; if(k == 0) return head;
    ListNode* fast = head; ListNode* slow = head; 
    ListNode* prev1 = NULL; ListNode* prev2 = NULL;
    for(int i = 0; i < k; i++) fast = fast->next;
    prev1 = fast;
    while(fast != NULL){
        prev1 = fast;
        fast = fast->next;
        prev2 = slow;
        slow = slow->next;
    }
    if(prev2 != NULL) prev2->next = NULL;
    prev1->next = head;
    return slow;
}
int main(){
    return 0;
}