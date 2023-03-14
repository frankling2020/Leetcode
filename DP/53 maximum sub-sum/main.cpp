#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 0) return 0;
    int max_end = nums[0], maximum = nums[0];
    for (int ptr = 1; ptr < sz; ++ptr){
        max_end = max(max_end + nums[ptr], nums[ptr]);
        if (max_end > maximum) maximum = max_end;
    }
    return maximum;
}