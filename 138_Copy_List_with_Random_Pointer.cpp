#include <iostream>
using namespace std;
// This solution is based on the discuss in LeetCode
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if(head == NULL) return NULL;
    RandomListNode* l1 = head; RandomListNode* l2 = head;
    while(l1 != NULL){
        l2 = new RandomListNode(l1->label);
        l2->next = l1->next;
        l1->next = l2;
        l1 = l2->next;
    }
    l1 = head;
    while(l1 != NULL){
        if(l1->random != NULL){
            l1->next->random = l1->random->next;
        }
        l1 = l1->next->next;
    }
    // l10 - l20 - l11 - l21 - l13 - l23
    RandomListNode* l2Head = head->next;
    l2 = head->next;
    head->next = l2->next;
    l1 = l2->next;
    while(l1 != NULL){
        l2->next = l1->next;
        l2 = l1->next;
        l1->next = l1->next->next;
        l1 = l1->next;
    }
    return l2Head;
}
int main(){
    return 0;
}