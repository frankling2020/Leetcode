/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto list: lists) {
            if (list) pq.push(list);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while (!pq.empty()) {
            ListNode* first = pq.top();
            pq.pop();
            p->next = first;
            if (first->next) {
                pq.push(first->next);;
            }
            first->next = nullptr;
            p = p->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};