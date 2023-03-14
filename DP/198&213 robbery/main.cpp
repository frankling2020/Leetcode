#include <vector>
using namespace std;

class Solution {
public:
    int robRange(vector<int> &nums, const int& start, const int& end){
        int first = 0, second = 0, temp = 0;
        for (int index = start; index < end; index++){
            temp = second;
            if (first + nums[index] > second) second  = first + nums[index];
            first = temp;
        }
        return second;
    }
    
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        return max(robRange(nums, 0, sz -1), robRange(nums, 1, sz));  
    }
};