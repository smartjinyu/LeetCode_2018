#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false; int res = 0; 
    ListNode *head = l1;
    ListNode *prev = l1;
    while(l1 != NULL && l2 != NULL){
        res = l1->val + l2->val + carry;
        carry = false;
        if(res >= 10){
            res -= 10; carry = true;
        }
        l1->val = res;
        prev = l1;
        l1 = l1->next; l2 = l2->next;
    }

    if(l1 == NULL && l2 == NULL){
        if(carry){
            prev->next = new ListNode(1);
        }
        return head;
    }else if(l1 == NULL){
        prev->next = l2;
        while(carry && l2 != NULL){
            res = l2->val + carry;
            carry = false;
            if(res >= 10){
                res -= 10; carry = true;
            }
            l2->val = res;
            prev = l2; l2 = l2->next;
        }
        if(l2 == NULL && carry){
            prev->next = new ListNode(1);
        }
        return head;
    }else{
        prev->next = l1;
        while(carry && l1 != NULL){
            res = l1->val + carry;
            carry = false;
            if(res >= 10){
                res -= 10; carry = true;
            }
            l1->val = res;
            prev = l1; l1 = l1->next;
        }
        if(l1 == NULL && carry){
            prev->next = new ListNode(1);
        }
        return head;
    }
    return head;
}
int main(){
    ListNode l10(2),l11(4),l12(3);
    l10.next = &l11; l11.next = &l12;
    ListNode l20(5),l21(6),l22(9);
    l20.next = &l21; l21.next = &l22;
    ListNode* ans = addTwoNumbers(&l10,&l20);
    while(ans != NULL){
        printf("%d ",ans->val); ans = ans->next;
    }
    return 0;
}