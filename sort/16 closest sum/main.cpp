#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2], sum;
        const size_t sz = nums.size();
        size_t left, right;
        for (size_t i = 0; i < sz; ++i){
            left = i + 1;
            right = sz - 1;
            while (left < right){
                sum = nums[i] + nums[left] + nums[right];
                if (std::abs(sum - target) < std::abs(closest - target)) closest = sum;
                if (sum < target) ++left;
                else if (sum > target) --right;
                else return sum; // basic case
            }
            while (i + 1 < sz && nums[i] == nums[i+1]) ++i;
        }
        return closest;
    }
};