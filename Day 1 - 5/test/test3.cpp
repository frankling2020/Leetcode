#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int sz = s.length();
        int maximum = 0;
        unordered_set<int> char_set;
        for (int left = 0; left < sz && right < sz; ++left) {
            if (left != 0) char_set.erase(s[left-1]);
            while (left <= right && right < sz && char_set.count(s[right]) == 0) {
                char_set.insert(s[right]);
                ++right;
            }
            if (maximum < right - left) maximum = right - left;
        }
        return maximum;
    }
};