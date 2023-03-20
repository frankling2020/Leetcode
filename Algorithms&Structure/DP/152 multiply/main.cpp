#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxF *= nums[i];
            minF *= nums[i];
            if (maxF < minF) swap(maxF, minF);
            if (maxF < nums[i]) maxF = nums[i];
            if (minF > nums[i]) minF = nums[i];
            if (maxF > ans) ans = maxF;
        }
        return ans;
    }
};
