#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        int* dp = new int[sz];
        for (int i = 0; i < sz; ++i) dp[i] = 0;
        for (int row = 0; row < sz; ++row){
            for (int col = row; col >= 0; --col){
                if (col != 0 && (col == row || dp[col] > dp[col-1])) dp[col] = dp[col-1];
                dp[col] += triangle[row][col]; 
            }
        }
        int ans = dp[0];
        for (int i = 1; i < sz; ++i) if (ans > dp[i]) ans = dp[i];
        delete [] dp;
        return ans;
    }
};