#include <vector>
using namespace std;

class Solution {
public:
    // 121
    int oneMaxProfit(vector<int>& prices) {
        int minprice = prices[0], maxprofit = 0;
        for (int price : prices){
            if (maxprofit < price - minprice) maxprofit = price - minprice;
            else if (minprice > price) minprice = price;
        }
        return maxprofit;
    }

    // 122 & 714
    int mulMaxProfit(vector<int>& prices, int fee = 0) {
        int buy = -prices[0] - fee;
        int sell = 0;
        for (int price : prices){
            buy = max(buy, sell - price - fee);
            sell = max(sell, buy + price);
        }
        return sell;
    }

    // 123 & 188
    int limitedMaxProfit(vector<int>& prices, int isAllow=2) {
        if (prices.size() == 0) return 0;
        int sz = isAllow*2 + 1;
        vector<int> arr(sz,0);
        // initial state: arr[0]
        for (int i = 1; i < sz; i += 2) arr[i] = - prices[0];
        for (int price : prices){
            for (int ptr = 1; ptr < sz; ptr+=2){
                // add slackness that it stores the best profit with no more than i times buy&sale
                // if exactly change the order
                arr[ptr] = max(arr[ptr], arr[ptr - 1] - price);
                arr[ptr+1] = max(arr[ptr+1], arr[ptr] + price);
            }
        }
        return arr[sz-1];
    }

    // 309
    int cooledMaxProfit(vector<int>& prices) {
        vector<int> dp(3, 0);
        dp[0] = -prices[0];
        for (int price : prices){
            // buy: depend on previous cooldown
            if (dp[0] < dp[2] - price) dp[0] = dp[2] - price;
            // cooldown: depend on previous sell
            if (dp[1] > dp[2]) dp[2] = dp[1];
            // sell: possible sell day
            if (dp[1] < dp[0] + price) dp[1] = dp[0] + price;

        }
        return dp[1];
    }
};