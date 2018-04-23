#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* cur = head;
    while(cur != NULL){
        if(cur->val == val){
            cur = cur->next;
            prev->next = cur;
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return dummy->next;
}

int main(){
    return 0;
}