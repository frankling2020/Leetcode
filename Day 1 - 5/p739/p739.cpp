#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        vector<int> res(sz, 0);
        stack<int> q;
        for (int i = 0; i < sz; ++i) {
            while (!q.empty() && temperatures[q.top()] < temperatures[i]) {
                res[q.top()] = i - q.top();
                q.pop();
            }
            q.push(i);
        }
        while (!q.empty()) {
            res[q.top()] = 0;
            q.pop();
        }
        return res;
    }
};