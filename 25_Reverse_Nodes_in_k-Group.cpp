#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse(ListNode* prev0, int k){
    // return the tail of the new list
    ListNode* tail = prev0->next;
    ListNode* prev = prev0;
    ListNode* cur = prev->next; ListNode* next;
    for(int i = 0; i < k; i++){
        next = cur->next;
        cur->next = prev;
        prev = cur; cur = next;
    }
    prev0->next = prev;
    return tail;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    if(k == 1) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy; ListNode* cur = head;
    while(true){
        int i = 1;
        while(cur != NULL && i < k){
            i++;
            cur = cur->next;
        }
        if(cur == NULL) return dummy->next;
        cur = cur->next; // head of next k elements
        prev = reverse(prev,k);
        prev->next = cur;
    }
}
int main(){
    return 0;
}