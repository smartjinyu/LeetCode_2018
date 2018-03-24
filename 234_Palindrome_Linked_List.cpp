#include <iostream>
using namespace std;
bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL){ // fast->next == NULL, list has odd nodes
        slow = slow->next;
    }
    prev->next = NULL; // cut the half of the list
    // reverse the second half of the list
    prev = NULL; ListNode* cur = slow; ListNode* next = slow;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur; cur = next;
    }
    ListNode* head2 = prev;
    while(head != NULL && head2 != NULL){
        if(head->val != head2->val) return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}
int main(){
    return 0;
}