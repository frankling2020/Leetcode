#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> q;

        vector<int> res;
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            res.push_back(0);
            if (!q.empty()) {
                while (!q.empty() && (q.top()).second < ptr->val) {
                    res[(q.top()).first] = ptr->val;
                    q.pop();
                }
            }
            q.emplace(cnt, ptr->val);
            ++cnt;
            ptr = ptr->next;
        }
        return res;
    }
};