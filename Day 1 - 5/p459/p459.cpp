#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.length();
        string c = s + s;

        vector<int> go_back(sz, -1);
        int left = 0;
        int right = 1;

        while (right < sz) {
            // find a place they can compare that satisfies [0, left] == [right - left + 1, right]
            while (left != 0 && s[left] != s[right]) left = go_back[left-1] + 1;
            if (s[left] == s[right]) go_back[right] = left;
            else {go_back[right] = -1; left = -1;}
            ++left;
            ++right;
        }

        int ptr = 0;
        for (int x = 1; x < 2 * sz - 1; ++x) {
            while (ptr != 0 && c[x] != s[ptr]) ptr = go_back[ptr-1] + 1;
            if (c[x] == s[ptr]) ++ptr;
            else ptr = 0;
            if (ptr == sz) break;
        }
        return ptr == sz;
    }
};