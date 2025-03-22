class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
    LRUCache(int capacity) {
        size = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void insertAfterHead(Node* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void deletion(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deletion(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deletion(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size() == size){
                Node* lastNode = tail->prev;
                mpp.erase(lastNode->key);
                deletion(lastNode);
                delete lastNode;
            }
            Node* newNode = new Node(key,value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
