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
//DoubleListNode* tail = nullptr;

int main()
{
    /*for(DoubleListNode* p = head;p!=nullptr;p = p->next){
            cout << p->val << endl;
            tail = p;
    }
    for(DoubleListNode* p = tail;p!=nullptr;p = p->prev){
        cout << p->val << endl;
    }
    DoubleListNode* newNode = new DoubleListNode(66);
    newNode->next = head;
    head->prev = newNode;      从头到尾遍历和从尾到头遍历
    head = newNode;*/


    /*DoubleListNode* tail = head;
    while(tail->next != nullptr)
    {
        tail = tail->next;
    } 
    DoubleListNode* newNode1 = new DoubleListNode(77);
    tail->next = newNode1;
    newNode1->prev = tail;
    tail = newNode1;

    for(DoubleListNode* q = head;q!=nullptr;q=q->next)
    {
        cout << q->val <<" ";
    }                                               未定尾指针，先循环遍历找到尾指针然后再进行尾插法
    cout << endl;*/

    /*
    DoubleListNode* p = head;
    for(int i = 0;i < 2; i++){
        p = p->next;
    }
    DoubleListNode* newNode = new DoubleListNode(66);
    newNode->next = p->next;
    p->next = newNode;
    newNode->prev = newNode->next->prev;
    newNode->next->prev = newNode;

    for(DoubleListNode* q = head;q!=nullptr;q=q->next)
    {
        cout << q->val <<" ";
    }                中间插入节点                                 
    cout << endl;*/

    /*
    DoubleListNode* p = head;
    for(int i = 0;i < 2; i++){
        p = p->next;
    }
    p->next = p->next->next;

    for(DoubleListNode* q = head;q!=nullptr;q=q->next)
    {
        cout << q->val <<" ";
    }                                   不建议这样删除节点，这样会造成内存泄漏捏，凡是new申请的内存，都需要delete去删除           
    cout << endl; */

    /*
    DoubleListNode* p = head;
    for(int i = 0; i < 2; i++){
        p = p->next;
    }
    DoubleListNode* toDelete = p->next;
    p->next = toDelete->next;
    toDelete->next->prev = p;
    
    toDelete->prev = nullptr;
    toDelete->next = nullptr;
                                    删除中间节点
    delete toDelete;*/

    /*
    DoubleListNode* p = head;
    head = head->next;
    head->prev = nullptr;

    p->next = nullptr;
    p->prev = nullptr;
                        删除头节点的值
    delete p;*/

    DoubleListNode* p = head;
    while(p->next->next != nullptr){
        p = p->next;
    }
    DoubleListNode* q = p->next;

    q->next = nullptr;
    q->prev = nullptr;
    delete q; 
    DoubleListNode* tail = p;
}
