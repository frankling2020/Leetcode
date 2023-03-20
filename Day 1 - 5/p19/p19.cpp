#include <iostream>
using namespace std;


class Solution {
public:
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // dummy node
        ListNode* dummyNode = new ListNode(-1, head);
        
        ListNode* slowNode = dummyNode;
        ListNode* fastNode = dummyNode;
        while (fastNode && n >= 0) {fastNode = fastNode->next; --n;}
        if (n >= 0) return nullptr;
        while (fastNode) {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }
        ListNode* delNode = slowNode->next;
        cout << delNode->val << endl;
        ListNode* nextNode = delNode->next;
        slowNode->next = nextNode;
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        delete delNode;
        return newHead;
    }
};