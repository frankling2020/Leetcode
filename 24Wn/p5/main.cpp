// Manacher Algorithm

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int expand(const string& s, int left, int right) {
        int sz = s.length();
        while (left >= 0 && right < sz && s[left] == s[right]) {
            --left;
            ++right;
        }
        return max((right - left - 2) / 2, 0);
    }

    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }
        int sz = t.length();
        vector<int> arm_len(sz, 0);
        int max_pivot = 0;
        int boundary_pivot = 0;
        int cur_arm_len = 0;
        int right = 0;
        for (int i = 1; i < sz; ++i) {
            if (right >= i) {
                int min_arm_len = min(arm_len[2 * boundary_pivot - i], right - i);
                cur_arm_len = expand(t, i - min_arm_len, i + min_arm_len);
            }
            else {
                cur_arm_len = expand(t, i, i);
            }
            arm_len[i] = cur_arm_len;
            if (i + cur_arm_len > right) {
                boundary_pivot = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len > arm_len[max_pivot]) {
                max_pivot = i;
            }
        }
        string ans;
        for (int i = max_pivot - arm_len[max_pivot]; i < max_pivot + arm_len[max_pivot]; ++i) {
            if (t[i] != '#') {
                ans += t[i];
            }
        }
        return ans;
    }
};