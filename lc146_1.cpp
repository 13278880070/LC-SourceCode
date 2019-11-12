class Node {
private:
	int key;
	int value;
	Node *pre;
	Node *next;
	Node(int key, int value) {
		this->key = key; 
		this->value = value; 
		this->pre = NULL; 
		this->next = NULL;
	}
};

class LRUCache {
private:
    int capacity;
    int count;
    unordered_map<int, Node*> map;
    // 最新, 最久.
    Node *head;
    Node *tail;

    // 单纯的对 Node 的操作.
    void removenode() {
    	Node *mnode = tail->pre;
    	tail->pre = mnode->pre;
        mnode->pre->next = tail;
    	map.erase(mnode->key);
    }

    // key, value 添加新结点.
    void addnode(int key, int value) {
    	Node *adnode = new Node(key, value);
    	adnode->next = head->next;
    	adnode->pre = head;
    	head->next->pre = adnode;
    	head->next = adnode;

        map[key] = adnode;
    }

    void move2head(Node *node) {
    	if(node->pre != head) {
            // node 从原位置移出.
            node->pre->next = node->next;
            node->next->pre = node->pre;

            // 添加 node 到链表头部.
            node->next = head->next;
            node->pre = head;
            head->next->pre = node;
            head->next = node;
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->count = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    

    int get(int key) {
        if(map.find(key) == map.end()) {
        	return -1;
        }
        Node *node = map[key];
        move2head(node);
        return node->value;
    }
    
    void put(int key, int value) {
    	if(map.find(key) != map.end()) {
    		map[key]->value = value;
    		move2head(map[key]);
    	} else {
    		if(count == capacity) {
	            removenode();
	            count--;
	        }
	        addnode(key, value);
	        count++;
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */