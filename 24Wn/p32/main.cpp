#include <vector>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int sz = s.length();
        vector<int> dp(sz + 1, 0);
        int maximum = 0;
        for (int i = 2; i <= sz; ++i) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(') {
                    dp[i] = dp[i-2] + 2;
                }
                else {
                    int idx = i - 1 - dp[i-1];
                    if (idx > 0 && s[idx - 1] == '(') {
                        dp[i] = dp[i - 1] + dp[idx - 1] + 2;
                    } 
                }
            }
            if (maximum < dp[i]) maximum = dp[i];
        }

        return maximum;
    }
};