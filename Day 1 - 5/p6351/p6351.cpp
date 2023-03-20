#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> idx;
        int sz = nums.size();
        for (int i = 0; i < sz; ++i) idx.emplace_back(i);
        sort(idx.begin(), idx.end(), [&nums](const int& a, const int& b){return nums[a] < nums[b] || (nums[a] == nums[b] && a < b);});
        vector<bool> mark(sz, true);
        long long sum = 0;
        for (auto id: idx) {
            if (mark[id]) {
                sum += nums[id];
                mark[id] = false;
                if (id != 0 && mark[id-1]) mark[id-1] = false;
                if (id != sz-1 && mark[id + 1]) mark[id+1] = false;
            }
        }
        return sum;
    }
};