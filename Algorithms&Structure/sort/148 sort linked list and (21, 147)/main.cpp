#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* end = head, *cnt = head->next, *ptr, *prev;
        while (cnt){
            prev = nullptr;
            for (ptr = head; ptr != cnt && ptr->val <= cnt->val; prev = ptr, ptr = ptr->next);
            if (ptr != cnt){
                end->next = cnt->next;
                cnt->next = ptr;
                if (ptr == head) head = cnt;
                else prev->next = cnt;
            }
            else end = cnt;
            cnt = end->next;
        }
        return head;
    }

    // l1 and l2 are not connected to each other
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        else{
            ListNode *prev = new ListNode(0);
            ListNode *cnt = prev;
            while (l1 || l2){
                if (l1 == nullptr) {cnt->next = l2; break;}
                else if (l2 == nullptr) {cnt->next = l1; break;} 
                else if (l1->val < l2->val) {cnt->next = l1; l1 = l1->next;}
                else {cnt->next = l2; l2 = l2->next;}
                cnt = cnt->next;
            }
            return prev->next;
        } 
    }


    inline ListNode* middle(ListNode* head, ListNode* tail){
        ListNode *slow = head, *fast = head;
        while (fast != tail){
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }
        return slow;
    }

    // very careful with head->next = nullptr
    // disconnect the point from its original next
    ListNode* mergesort(ListNode* head, ListNode* tail){
        if (head == nullptr) return head;
        else if (head->next == tail) {head->next = nullptr; return head;}
        ListNode *mid = middle(head, tail);
        ListNode *ptr1 = mergesort(head, mid), *ptr2 = mergesort(mid, tail);
        return merge(ptr1, ptr2);
    }

    
    ListNode* mergesort(ListNode* head){
        if (head == nullptr) return head;
        int sz = 0;
        ListNode* guard = new ListNode(0, head);
        ListNode* cnt = head, *prev, *temp;
        ListNode *head1, *head2;
        while (cnt) {cnt = cnt->next; ++sz;}
        for (int len = 1; len < sz; len <<= 1){
            // be careful here begins with 1
            prev = guard;
            cnt = guard->next;
            while (cnt) {
                head1 = cnt;
                for (int num = 1; num < len && cnt->next; ++num) cnt = cnt->next;
                head2 = cnt->next;
                cnt->next = nullptr;
                cnt = head2;
                for (int num = 1; num < len && cnt && cnt->next; ++num) cnt = cnt->next;
                temp = nullptr;
                if (cnt){
                    temp = cnt->next;
                    cnt->next = nullptr;
                }
                prev->next = merge(head1, head2);
                // cnt may be changed to other places                
                while (prev->next) prev = prev->next;
                cnt = temp;
            }
        }
        return guard->next;
    }


    ListNode* sortList(ListNode* head) {
        return mergesort(head, nullptr);
    }
};