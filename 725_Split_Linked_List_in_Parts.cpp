#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int len = 0;
    ListNode* node = root;
    while(node != NULL){
        node = node->next; len++;
    }
    int quotient = len/k;
    int remain = len - quotient*k;
    vector<ListNode*> res;
    node = root; int cnt = 0;
    ListNode* head = root; ListNode* prev = root;
    for(int i = 0; i < remain; i++){
        cnt = 0;
        while(cnt < quotient + 1){
            prev = node;
            node = node->next; cnt++;               
        } // prev is the tail of the current list, node is the head of next list
        res.push_back(head);
        prev->next = NULL;
        head = node;
    }

    for(int i = 0; i < k - remain; i++){
        cnt = 0;
        while(cnt < quotient){
            prev = node;
            node = node->next; cnt++;               
        } // prev is the tail of the current list, node is the head of next list
        if(quotient != 0){
            res.push_back(head);
            prev->next = NULL;
            head = node;
        }else{
            res.push_back(NULL);
        }
    }
    return res;

}
int main(){
    return 0;
}