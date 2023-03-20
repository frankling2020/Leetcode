#include <vector>
#include <string>
using namespace std;

class Solution {
    // Bag problem:
    // particle, volume, decision
public:
    // 416
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums)  sum += num;
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<bool> a(sum+1, false);
        a[0] = true;
        for (int num : nums){
            for (int ptr = sum - num; ptr >= 0; --ptr){
                if (a[ptr] && !a[ptr+num]) 
                    a[ptr+num] = true;
            }
        }
        return a[sum];
    }

    // 494
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        sum += target;
        if (sum < 0 || sum % 2 == 1) return false;
        sum /= 2;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for (int num : nums){
            for (int ptr = sum - num; ptr >= 0; --ptr){
                if (dp[ptr] != 0) dp[ptr+num] = dp[ptr+num] + dp[ptr];
            }
        }
        return dp[sum];
    }

    // 322
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (int num = 0; num <= amount; ++num){
            for (int coin : coins){
                if (num - coin >= 0 && dp[num-coin] >= 0 && (dp[num] < 0 || dp[num - coin] + 1 < dp[num])){
                    dp[num] = dp[num-coin] + 1;
                }
            }
        }
        return dp[amount];
    }

    // 518 
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int num = 0; num <= amount; ++num) {
                if (num - coin >= 0 && dp[num-coin] > 0){
                    dp[num] += dp[num-coin];
                }
            }
        }
        return dp[amount];
    }

    // 474
    int getZerosOnes(string& str) {
        int ans = 0;
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '0') ++ans;
        }
        return ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size(), zeros, ones;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; ++i) {
            zeros = getZerosOnes(strs[i]);
            ones = strs[i].size() - zeros;
            for (int j = m; j >= zeros; --j) {
                for (int k = n; k >= ones; --k) {
                    if (dp[j][k] < dp[j - zeros][k - ones] + 1)
                        dp[j][k] = dp[j - zeros][k - ones] + 1;
                }
            }
        }
        return dp[m][n];
    }    
};