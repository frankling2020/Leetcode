#include <iostream>
using namespace std;


class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* prev;
        LinkedNode* next;
        LinkedNode(int val): val(val), prev(nullptr), next(nullptr) {};
    };

    MyLinkedList(): size(0), head(new LinkedNode(0)), tail(new LinkedNode(0)) {
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        LinkedNode* ptr = find_nth_prev(index);
        return (ptr && ptr->next)? ptr->next->val:-1;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);
        LinkedNode* prevNode = this->head;
        connect(prevNode, newHead);
        ++size;
    }
    
    void addAtTail(int val) {
        LinkedNode* newTail = new LinkedNode(val);
        LinkedNode* prevNode = this->tail->prev;
        connect(prevNode, newTail);
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index == size) addAtTail(val);
        else {
            LinkedNode* prevNode = find_nth_prev(index);
            if (prevNode) {
                LinkedNode* nextNode = prevNode->next;
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
        else if (index == 0) return this->head;
        else if (index == this->size - 1) return this->tail->prev->prev; 
        LinkedNode* prevNode = this->head;

        int ptr = 0;
        while (prevNode && ptr < index) {prevNode = prevNode->next; ++ptr;}
        return prevNode;
    }

    void connect(LinkedNode* prevNode, LinkedNode* newNode) {
        LinkedNode* nextNode = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (nextNode) nextNode->prev = newNode;
        newNode->next = nextNode;
    }

    void disconnect(LinkedNode* prevNode, LinkedNode* delNode) {
        LinkedNode* nextNode = delNode->next;
        prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;
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