#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next = head;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur; cur = next;
    }
    return prev;
    
}
void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL) return;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL){
        slow = slow->next;
        prev = prev->next;
    }
    prev->next = NULL; // first half of the list may be one node longer than the second
    ListNode* head2 = reverse(slow);
    ListNode* next = NULL; ListNode* next2 = NULL;
    while(head2 != NULL){
        next = head->next;
        next2 = head2->next;
        head->next = head2;
        head2->next = next;
        head = next; head2 = next2;
    }
}
int main(){
    return 0;
}