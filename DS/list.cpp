#include <iostream>
#include <vector>
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* createLinkedList(std::vector<int> arr){
    if(arr.empty()){
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++){
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

ListNode* head = createLinkedList({1, 2, 3, 4, 5});
int main(){
    /*for (ListNode* p = head; p != nullptr; p = p->next){
        std::cout << p->val << std::endl;
    }// Output: 1 2 3 4 5*/

    ListNode* newNode = new ListNode(0);
    newNode->next = head;
    head = newNode;// Insert 0 at the beginning 头插法

    /*ListNode* p = head;
    while(p != nullptr){
        p = p->next;
    }
    p->next = new ListNode(6);// Insert 6 at the end 尾插法*/

    ListNode* p = head;
    for(int i = 0; i < 2; i++){
        p = p->next;
    } 
    ListNode* newNode2 = new ListNode(66);
    newNode2->next = p->next;
    p->next = newNode2;// Insert 66 after the third node 这里的p指向第三个节点头节点算一个节点 
}
