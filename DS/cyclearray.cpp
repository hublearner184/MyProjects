#include <iostream>
#include <vector>
#include <stdexcept>
#include <ostream>
using namespace std;

template<typename T>
class CycleArray{
    std::vector<T>arr;
    int start;
    int end;
    int count;

    void resize(int newSize){
        std::vector<T> newArr(newSize);
        for (int i = 0; i< arr.size(); i++){
            newArr[i] = arr[i];
        }
        
    }

};
