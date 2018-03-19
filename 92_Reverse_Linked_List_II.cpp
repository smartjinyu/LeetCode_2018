#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL) return NULL;
    ListNode* prev = head; // the node before reversed list
    ListNode* node; // first node of reverse list 
    if(m == 1){
        prev = NULL; node = head;
    }else{
        for(int i = 0; i < m - 2; i++){
            prev = prev->next;
        }
        node = prev->next;
    }
    ListNode* preHead = node;
    ListNode* temp = node; ListNode* next = NULL;
    for(int i = 0; i < n-m; i++){
        next = node->next;
        node->next = temp;
        temp = node; node = next;
    }
    next = node->next;
    node->next = temp;
    preHead->next = next;
    if(prev == NULL){
        return node;
    }else{
        prev->next = node;
        return head;
    }
}
int main(){
    return 0;
}