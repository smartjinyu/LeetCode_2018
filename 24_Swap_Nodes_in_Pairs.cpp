#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* dummy = new ListNode(0); dummy->next = head;
    ListNode* prev = dummy; ListNode* cur = head; ListNode* next = NULL;
    ListNode* nextnext = NULL;
    while(cur != NULL){
        next = cur->next;
        if(next == NULL) break;
        nextnext = next->next;
        prev->next = next;
        next->next = cur;
        cur->next = nextnext;
        prev = cur; cur = nextnext;
    }
    return dummy->next;
    
}
int main(){
    return 0;
}