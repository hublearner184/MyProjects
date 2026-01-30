#include <iostream>
#include <stdexcept>
#include <vector>

template<typename E>
class MyArrayList{
    private:
    E* data;//真正存储数据的底层数组

    int size;//当前元素个数

    int cap;//最大元素数量

    //默认初始容量
    static const int INIT_CAP = 1;
    public:
    MyArrayList(){
        this-> data = new E[INIT_CAP];
        this-> size = 0;
        this-> cap = INIT_CAP;
    }
    MyArrayList(int initCapacity){
        this-> data = new E[initCapacity];
        this-> size = 0;
        this-> cap = initCapacity;
    }
    void addLast(E e){
        if(size == cap){
            resize(2 * cap);
        }
        data[size] = e;
        size++;
    }
    void add(int index,E e)
    {
        checkPositionIndex(index);

        if(size == cap)
        {
            resize(2 * cap);
        }
        for(int i = size; i > index; i--){
            data[i] = data[i - 1];
        }
        data[index] = e;
        size++;
    }
    void AddFirst(E e){
        add(0,e);
    }
    E removeLast(){
        if(size == 0){
            throw std::out_of_range("No Such Element Exception");
        }
        if (size == cap / 4){
            resize(cap / 2);
        }
        E deletedVal = data[size - 1];
        data [size - 1] = E();
        size--;
        return deletedVal;
    }
    E remove(int index){
        checkElementIndex(index);
        if(size == cap / 4){
            resize(cap / 2);
        }
        E deletedVal = data[index];
        for(int i = index; i < size - 1; i++){
            data[i] = data[i + 1];
        }
        data[size - 1] = E();
        size--;
        return deletedVal;
    }
    E removeFirst(){
        return remove(0);
    }
    E get(int index){
        checkElementIndex(index);
        return data[index];
    }
    E set(int index,E element){
        checkElementIndex(index);
        E oldVal = data[index];
        data[index] = element;
        return oldVal;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void resize(int newCap){
        E* temp = new E[newCap];
        for(int i = 0; i < size; i++){
            temp[i] = data[i];
        }
        delete[] data;

        data = temp;
        cap = newCap;
    }
    bool isElementIndex(int index){
        return index >= 0 && index < size;
    }
    bool isPositionIndex(int index){
        return index >= 0 && index <= size;
    }
    void checkElementIndex(int index){
        if(!isElementIndex(index)){
            throw std::out_of_range("Index out of bounds");
        }
    }
    void checkPositionIndex(int index){
        if(!isPositionIndex(index)){
            throw std::out_of_range("Index out of bounds");
        }
    }
    void display(){
        std::cout << "ArrayList: size = " << size << ", capacity = " << cap << std::endl;
        for (int i = 0; i < size; i++){
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    ~MyArrayList(){
        delete[] data;
    }
};
int main(){
    MyArrayList<int> arr(3);

    for(int i = 0;i <= 5; i++){
        arr.addLast(i);
    }
    arr.remove(3);
    arr.add(1,9);
    arr.AddFirst(100);
    int val = arr.removeLast();

    for(int i = 0; i < arr.getSize(); i++){
        std::cout << arr.get(i) << std::endl;
    }
    return 0;
}