#include <iostream>
using namespace std;
// This solution is in referene to the discuss in LeetCode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    ListNode* fast = head->next->next;
    ListNode* slow = head->next;
    while(true){
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }else if(fast == slow){
            break;
        }else{
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

int main(){
    return 0;
}