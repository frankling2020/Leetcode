using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        int dp[n + 1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }

        for (int j = 2; j <= k; ++j) {
            int dp2[n + 1];
            int x = 1; 
            dp2[0] = 0;
            for (int m = 1; m <= n; ++m) {
                while (x < m && max(dp[x - 1], dp2[m - x]) >= max(dp[x], dp2[m - x - 1])) {
                    x++;
                }
                dp2[m] = 1 + max(dp[x - 1], dp2[m - x]);
            }
            for (int m = 1; m <= n; ++m) {
                dp[m] = dp2[m];
            }
        }
        return dp[n];
    }
};
