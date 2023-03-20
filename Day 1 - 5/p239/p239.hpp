#include <vector>
#include <deque>
#include <queue>
#include <iostream>
#include <assert.h>
using namespace std;


vector<int> maxSlidingWindow_Robust(vector<int>& nums, int k);
vector<int> maxSlidingWindow_Priority(vector<int>& nums, int k);
vector<int> maxSlidingWindow_Stack(vector<int>& nums, int k);


vector<int> maxSlidingWindow_Robust(vector<int>& nums, int k) {
    int sz = nums.size();
    deque<int> window(k);
    assert(k <= sz);
    
    vector<int> res;
    for (int i = k - 1; i >= 0; --i) {
        window[i] = nums[i];
        if (i != k -1 and window[i] < window[i+1]) {
            window[i] = window[i+1];
        }
    }

    res.push_back(window[0]);
    
    for (int i = k; i < sz; ++i){
        window.pop_front();
        window.push_back(nums[i]);
        
        int j = k - 1;
        while (j >= 1 and window[j] > window[j-1]) {
            window[j-1] = window[j];
            --j;
        }

        res.push_back(window[0]);
    }

    return res;
}


vector<int> maxSlidingWindow_Priority(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> q;
    vector<int> res;
    int sz = nums.size();
    for (int i = 0; i < k - 1; ++i) {
        q.emplace(nums[i], i);
    }
    for (int i = k - 1; i < sz; ++i) {
        q.emplace(nums[i], i);

        while (q.top().second <= i - k) {
            q.pop();
        }

        res.push_back(q.top().first);
    }
    return res;
}


vector<int> maxSlidingWindow_Stack(vector<int>& nums, int k) {
    deque<int> q;
    int sz = nums.size();

    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i) {
        while (!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
        if (q.empty() || nums[q.back()] > nums[i]) q.push_back(i);
        
        if (i >= k - 1){
            while (q.front() <= i - k) q.pop_front();
            assert(!q.empty());
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}