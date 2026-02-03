#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename E>
class MyLinkedList{
    struct Node{
        E val;
        Node* next;
        Node* prev;
        Node(E value):val(value),next(nullptr),prev(nullptr){}
    };
    Node* head;
    Node* tail;                                                                                         
    int size;
public:
    MyLinkedList(){
        head = new Node(E());
        tail = new Node(E());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    ~MyLinkedList(){
        while(size > 0 ){
            removeFirst();
        }
        delete head;
        delete tail;
    }
    void addLast(E e){
        Node* p = tail->prev;
        Node* newNode = new Node(e);
        newNode->next = p->next;
        newNode->prev = p;
        p->next = newNode;
        tail->prev = newNode;
        size++;
    }
    void addFirst(E e){
        Node* newNode = new Node(e);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        size++;
    }
    void add(int index,E e){
        checkPositionIndex(index);
        if(index == size){
            addLast(e);
            return;
        }
        Node* p = getNode(index);
        Node* newNode = new Node(e);
        newNode->next = p->next;
        p->next->prev = newNode;
        p->next = newNode;
        newNode->prev = p;
        size++;
    }
    E removeFirst(){
        if(size < 1){
            throw std::out_of_range("No elements to remove");
        }
        Node* p = head;
        Node* toDelete = head->next;
        p->next = toDelete->next;
        toDelete->next->prev = p;
        toDelete->next = nullptr;
        toDelete->prev = nullptr;
        E val = toDelete->val;
        delete toDelete;
        size--;
        return val;
    }
    E removeLast(){
        if(size < 1){
            throw std::out_of_range("No elements to remove");
        }
        Node* p = tail->prev->prev;
        Node* toDelete = tail->prev;
        p->next = tail;
        tail->prev = p;
        toDelete->next = nullptr;
        toDelete->prev = nullptr;
        E val = toDelete->val;
        delete toDelete;
        size--;
        return val;
    }
    E remove(int index){
        checkElementIndex(index);
        Node* toDelete = getNode(index);
        Node* prev = toDelete->prev;
        Node* next = toDelete->next;
        prev->next = next;
        next->prev = prev;
        toDelete->prev = nullptr;
        toDelete->next = nullptr;
        E val = toDelete->val;
        delete toDelete;
        size--;
        return val;
    }
    E get(int index){
        checkElementIndex(index);
        Node* p = getNode(index);
        return p->val;
    }
    E getFirst(){
        if(size < 1){
            throw std::out_of_range("No elements in the list");
        }
        return head->next->val;
    }
    E getLast(){
        if(size < 1){
            throw std::out_of_range("No elements in the list");
        }
        return tail->prev->val;
    }
    E set(int index,E e){
        checkElementIndex(index);
        Node* p = getNode(index);
        E oldVal = p->val;
        p->val = e;
        return oldVal;
    }
    int getSize() const {
        return size;
    }
    bool isEmpty() const{
        return size == 0;
    }
    void display(){
        std::cout << "size = " << size << std::endl;
        for(Node* p = head->next;p!=tail;p=p->next){
            std::cout << p->val << "<->";
        }
        std::cout << "nullptr" << std::endl;
        std::cout<< std::endl; 
    }
private:
    Node* getNode(int index){
        checkElementIndex(index);
        Node* p = head->next;
        for(int i = 0; i < index - 1 ; i++){
            p = p->next;
        }
        return p;
    }
    bool isElementIndex(int index) const {
        return index >= 0 && index < size;
    }
    bool isPositionIndex(int index) const {
        return index >= 0 && index <= size;
    }
    void checkElementIndex(int index) const {
        if(!isElementIndex(index)){
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
        }

    }
    void checkPositionIndex(int index) const {
        if(!isPositionIndex(index)){
            throw std::out_of_range("Index: " + std::to_string(index) + ", Size: " + std::to_string(size));
        }
    }
};

int main(){
    MyLinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    list.add(2,100);

    list.display();

    return 0;
}
