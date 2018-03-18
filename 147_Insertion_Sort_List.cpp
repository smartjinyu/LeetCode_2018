#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* search(ListNode* head, int target, int len){
    // return the last node s.t. node->val < target
    int cnt = 0;
    ListNode* node = head;
    ListNode* prev = NULL;
    while(cnt < len && node->val < target){
        prev = node; node = node->next;
        cnt++;
    }
    return prev;
}
ListNode* insertionSortList(ListNode* head) {
    if(head == NULL) return head;
    ListNode* node = head->next;
    ListNode* prev = head;
    int cnt = 1;
    while(node != NULL){
        ListNode* pos = search(head,node->val,cnt);
        cnt++;
        if(pos == NULL){
            prev->next = node->next;
            node->next = head; head = node;
            node = prev->next;
        }else if(pos == prev){
            prev = node; node = node->next;
        }else{
            ListNode* temp = pos->next;
            prev->next = node->next;
            pos->next = node;
            node->next = temp;
            node = prev->next;
        }
    }
    return head;
}
int main(){
    return 0;
}