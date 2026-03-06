#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:
    ListNode* FindNthFromEnd(ListNode* head,int x){
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i = 0; i < x; i++){
            p1 = p1->next;
        } //p1 walk x steps
        while(p1 != nullptr && p2 != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }// p2 is on the position
        return p2;
    }
    ListNode* removeNthFromEnd(ListNode* head,int x){
        ListNode* temp = FindNthFromEnd(head, x + 1);// find nth front node
        temp->next = temp->next->next;
        return head;
    }
};