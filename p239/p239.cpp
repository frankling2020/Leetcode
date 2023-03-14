#include "p239.hpp"


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return maxSlidingWindow_Robust(nums, k);
    }
};


int main(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (auto num: res) cout << num << " ";
    cout << endl;
}