#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        int left = intervals[0][0], right= intervals[0][1];
        for (auto item : intervals){
            if (item[0] > right) {merged.push_back({left, right}); left = item[0];} 
            if (item[1] > right) right = item[1];
        }
        merged.push_back({left, right}); 
        return merged;
    }
};