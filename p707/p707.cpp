#include <iostream>
using namespace std;


class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {};
    };

    MyLinkedList(): size(0), head(new LinkedNode(0)), tail(nullptr) {}
    
    int get(int index) {
        if (index >= size) return -1;
        LinkedNode* ptr = find_nth_prev(index);
        return (ptr && ptr->next)? (ptr->next)->val : -1;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);
        LinkedNode* prevNode = this->head;
        connect(prevNode, newHead);
        ++size;
        // new line
        if (size == 1) this->tail = newHead;
    }
    
    void addAtTail(int val) {
        LinkedNode* newTail = new LinkedNode(val);
        // new line
        LinkedNode* prevNode = (size == 0)? this->head:this->tail;
        connect(prevNode, newTail);
        ++size;
        // new line
        this->tail = newTail;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) addAtHead(val);
        else if (index == size) addAtTail(val);
        else {
            LinkedNode* prevNode = find_nth_prev(index);
            if (prevNode) {
                LinkedNode* newNode = new LinkedNode(val);
                connect(prevNode, newNode);
                ++size;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < size) {
            LinkedNode* prevNode = find_nth_prev(index);
            if (prevNode) {
                LinkedNode* delNode = prevNode->next;
                disconnect(prevNode, delNode);
                // new line
                if (index == size -1) this->tail = prevNode;
                --size;
            }
        }
    }

private:
    int size;
    LinkedNode* head;
    LinkedNode* tail;

    LinkedNode* find_nth_prev(int index) {
        if (index < 0 || index > this->size) return nullptr;
        LinkedNode* prevNode = this->head;

        int ptr = 0;
        while (prevNode && ptr < index) {prevNode = prevNode->next; ++ptr;}
        return prevNode;
    }

    void connect(LinkedNode* prevNode, LinkedNode* newNode) {
        LinkedNode* nextNode = prevNode->next;
        prevNode->next = newNode;
        // modified line
        newNode->next = (nextNode)? nextNode:nullptr;
    }

    void disconnect(LinkedNode* prevNode, LinkedNode* delNode) {
        LinkedNode* nextNode = delNode->next;
        // modified line
        prevNode->next = (nextNode)? nextNode:nullptr;
        delete delNode;
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
