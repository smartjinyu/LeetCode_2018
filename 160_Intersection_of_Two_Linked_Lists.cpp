#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* nodeA = headA; int lenA = 0;
    while(nodeA != NULL){
        lenA++; nodeA = nodeA->next;
    }
    ListNode* nodeB = headB; int lenB = 0;
    while(nodeB != NULL){
        lenB++; nodeB = nodeB->next;
    }
    if(lenA > lenB){
        for(int i = 0; i < lenA - lenB; i++){
            headA = headA->next;
        }
    }else{
        for(int i = 0;i < lenB - lenA; i++){
            headB = headB->next;
        }
    }
    while(headA != NULL){
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main(){
    return 0;
}