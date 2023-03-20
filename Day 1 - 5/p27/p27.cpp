#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = nums.size() - 1;
        while (ptr >= 0 and nums[ptr] == val) --ptr;
        for (int i = 0; i <= ptr; ++i) {
            if (nums[i] == val) {
                if (ptr >= 0) {
                    int temp = nums[i];
                    nums[i] = nums[ptr];
                    nums[ptr] = temp;
                    while (ptr >= 0 and nums[ptr] == val) --ptr;
                }
            }
        }
        return ptr + 1;
    }
};