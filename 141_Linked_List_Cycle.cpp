#include <iostream>
using namespace std;
// This solution is in reference to the discuss in LeetCode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head == NULL){
        return false;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast != NULL & fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

int main(){
    return 0;
}