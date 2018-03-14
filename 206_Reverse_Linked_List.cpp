#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* succ = NULL;
    ListNode* curNode = head;
    while(curNode != NULL){
        succ = curNode->next;
        curNode->next = prev;
        prev = curNode; curNode = succ;
    }
    return prev;
}

int main(){
    return 0;
}