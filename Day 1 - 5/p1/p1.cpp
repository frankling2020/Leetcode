#include "p1.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSum_twoPoints(nums, target);
    }
};

int main(int argc, char* argv[]) {
    Solution sol = Solution();
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = sol.twoSum(nums, 9);
    for (auto idx: res){
        cout << idx << " ";
        cout << endl;
    }
}