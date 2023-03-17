#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int binary_search(vector<int> cumsum, int query) {
        int left = 0, right = cumsum.size(), mid = 0;
        while (left < right) {
            mid = (left + right) / 2;
            if (cumsum[mid] == query) return mid + 1;
            else if (cumsum[mid] < query) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> cumsum(sz, 0);
        vector<int> res;
        cumsum[0] = nums[0];
        for (int i = 1; i < sz; ++i) cumsum[i] = cumsum[i-1] + nums[i];
        for (int i = 0; i < sz; ++i) cout << cumsum[i] << " ";
        cout << endl;
        for (int i = 0; i < queries.size(); ++i)
            res.emplace_back(binary_search(cumsum, queries[i]));
        return res;
    }
};