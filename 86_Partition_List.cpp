#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy; ListNode* cur = head;
    ListNode* dummy2 = new ListNode(0);
    ListNode* cur2 = dummy2;
    while(cur != NULL){
        if(cur->val >= x){
            cur2->next = cur;
            cur2 = cur;
            prev->next = cur->next;
        }else{
            prev->next = cur;
            prev = cur;
        }
        cur = cur->next;
    }
    if(cur2 != NULL) cur2->next = NULL;
    prev->next = dummy2->next;
    return dummy->next;
}
int main(){
    return 0;
}