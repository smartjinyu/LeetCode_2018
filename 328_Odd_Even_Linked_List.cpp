#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return head;
    }
    ListNode* oddHead = head;
    ListNode* evenHead = head->next;
    ListNode* preOdd = head;
    ListNode* preEven = evenHead;
    ListNode* curNode = head->next->next;
    int cnt = 3;
    while(curNode != NULL){
        if(cnt%2 == 1){
            // odd
            preOdd->next = curNode;
            preOdd = curNode;
        }else{
            // even
            preEven->next = curNode;
            preEven = curNode;
        }
        curNode = curNode->next;
        cnt++;
    }
    preOdd->next = evenHead;
    preEven->next = NULL;
    return oddHead;
}
int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2; node2.next = &node3; node3.next = &node4; node4.next = &node5;
    ListNode* result = oddEvenList(&node1);
    while(result != NULL){
        printf("%d ",result->val);
        result = result->next;
    }
    return 0;
}