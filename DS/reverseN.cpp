#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
class Solution{
public:
    ListNode* reverseM(ListNode* head,int n){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;

        while(n > 0){
            cur -> next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            n--;
        }

        head->next = cur;
        return pre;
    }
};