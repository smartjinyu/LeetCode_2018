#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwo(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val <= l2->val){
        l1->next = mergeTwo(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwo(l1,l2->next);
        return l2;
    }
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    while(lists.size() > 1){
        for(int i = 0; i < lists.size()/2; i++){
            lists[i] = mergeTwo(lists[2*i],lists[2*i+1]);
        }
        if(lists.size()%2 == 0){
            lists.resize(lists.size()/2);
        }else{
            lists[lists.size()/2] = lists[lists.size() - 1];
            lists.resize(lists.size()/2+1);
        }
    }
    return lists[0];
}
int main(){
    return 0;
}