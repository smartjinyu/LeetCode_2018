#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// This solution is in reference to the discuss in LeetCode
// space complexity is O(logn)
ListNode* merge(ListNode* l1, ListNode* l2){
    if(l1 == NULL){
        return l2;
    }else if( l2 == NULL){
        return l1;
    }else if(l1->val < l2->val){
        l1->next = merge(l1->next,l2);
        return l1;
    }else{
        l2->next = merge(l1,l2->next);
        return l2;
    }
}
ListNode* sortList(ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = head;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    ListNode* l1 = sortList(head); ListNode* l2 = sortList(slow);
    return merge(l1,l2);
}

int main(){
    return 0;
}