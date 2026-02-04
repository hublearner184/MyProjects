#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

class ExampleChainingHashMap{
    struct KVNode{
        int key;
        int value;
        KVNode(int key,int value):key(key),value(value){}
    };
    std::vector<std::list<KVNode>> table;
    public:
        ExampleChainingHashMap(int capacity):table(capacity){}

        int hash(int key){
            return key % table.size();//除留取余法
        }

        int get(int key){
            int index = hash(key);
            if(table[index].empty()){
                return -1;
            }
            for(const auto& node : table[index]){
                if(node.key == key){
                    return node.value;
                }
            }
            return -1;
        }
        void put(int key,int value){
            int index = hash(key);
            if(table[index].empty()){
                table[index].push_back(KVNode(key,value));
                return;
            }
            for(auto& node : table[index]){
                if(node.key == key){
                    node.value = value;
                    return;
                }
            }
            table[index].push_back(KVNode(key,value));
        }
        void remove(int key){
            auto& list = table[hash(key)];
            if(list.empty()){
                return;
            }
            list.remove_if([key](KVNode & node){return node.key == key;});
        }
};