class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {};
    };

    MyLinkedList(): size(0), head(nullptr) {}
    
    int get(int index) {
        LinkedNode* node = get_nth_node(index);
        return (node)? node->val:-1;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        if (size == 0) this->head = newNode;
        else {
            newNode->next = this->head;
            this->head = newNode;
        }
        ++size;
    }
    
    void addAtTail(int val) {
        if (size == 0) addAtHead(val);
        else insert_node(get_nth_node(size - 1), new LinkedNode(val));
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else insert_node(get_nth_node(index - 1), new LinkedNode(val));
    }
    
    void deleteAtIndex(int index) {
        if (index == 0) {
            LinkedNode* tmp = this->head;
            this->head = (tmp->next)? tmp->next:nullptr;
            --size;
        }
        else {
            LinkedNode* prevNode = get_nth_node(index - 1);
            LinkedNode* delNode = (prevNode)? prevNode->next:nullptr;
            remove_node(prevNode, delNode);
        }
    }

private:
    int size;
    LinkedNode* head;

    LinkedNode* get_nth_node(int index) {
        if (index < 0 || index >= size) return nullptr;
        LinkedNode* ptr = this->head;
        while (ptr && index) {ptr = ptr->next; --index;}
        return ptr;
    }

    void insert_node(LinkedNode* prevNode, LinkedNode* newNode) {
        if (prevNode) {
            newNode->next = (prevNode->next)? prevNode->next:nullptr;
            prevNode->next = newNode;
            ++size;
        }
    }

    void remove_node(LinkedNode* prevNode, LinkedNode* delNode) {
        if (prevNode && delNode) {
            prevNode->next = (delNode->next)? delNode->next:nullptr;
            delete delNode;
            --size;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */