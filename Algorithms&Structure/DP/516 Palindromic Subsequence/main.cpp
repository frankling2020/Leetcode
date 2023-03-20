#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.length();
        if (sz < 2) return sz;
        vector<int> dp1(sz, 0);
        vector<int> dp2(sz, 0);
        for (int begin = sz - 1; begin >= 0; --begin){
            for (int end = begin + 1; end < sz; ++end){
                if (s[begin] == s[end]) dp2[end] = dp1[end-1] + 2;
                else dp2[end] = max(dp2[end-1], dp1[end]);
            }
            dp2[begin] = 1;
            dp1 = dp2;
        }
        return dp1[sz-1];
    }
};