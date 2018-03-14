#include <iostream>
using namespace std;
// This solution is in reference to the discuss in LeetCode

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    while(fast != NULL){
        fast = fast->next;
        prev = slow;
        slow = slow->next;
    }
    if(prev != NULL){
        prev->next = slow->next;
        return head;
    }else{
        return head->next;
    }
}

int main(){
    return 0;
}