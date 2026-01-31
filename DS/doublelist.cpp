#include <iostream>
#include <vector>
using namespace std; 
class DoubleListNode{
    public:
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;
    DoubleListNode(int x):val(x),prev(NULL),next(NULL){}//构造函数
};

DoubleListNode* createDoubleLinkedList(const vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }
    DoubleListNode* head = new DoubleListNode(arr[0]);
    DoubleListNode* cur = head;

    for(int i = 1; i < arr.size(); i++){
        DoubleListNode* p = new DoubleListNode(arr[i]);
        cur->next = p;
        p->prev = cur;
        cur = cur->next;
    }
    return head;
}

DoubleListNode* head = createDoubleLinkedList({1,2,3,4,5});
DoubleListNode* tail = nullptr;

int main()
{
    for(DoubleListNode* p = head;p!=nullptr;p = p->next){
        


    }
}
