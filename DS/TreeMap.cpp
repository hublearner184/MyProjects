template <typename K, typename V>
class TreeNode{
public:
    K key;
    V value;
    TreeNode<K,V>* left;
    TreeNode<K,V>* right;
    TreeNode(K key,V val): key(key),value(val),left(nullptr),right(nullptr){}
};
