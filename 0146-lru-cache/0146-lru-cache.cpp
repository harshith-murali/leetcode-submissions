class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* previousNode = node->prev;
        Node* nextNode = node->next;

        previousNode->next = nextNode;
        nextNode->prev = previousNode;
    }

    void addToFront(Node* node) {
        Node* firstNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = firstNode;
        firstNode->prev = node;
    }

    int get(int key) {
        // miss
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        // hit
        Node* node = mp[key];

        removeNode(node);
        addToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        // element found
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->value = value;

            removeNode(node);
            addToFront(node);

            return;
        }
        // capacity full
        if (mp.size() == capacity) {
            Node* lruNode = tail->prev;

            removeNode(lruNode);
            mp.erase(lruNode->key);
            delete lruNode;
        }
        // element missing
        Node* newNode = new Node(key, value);

        addToFront(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key, value);
 */